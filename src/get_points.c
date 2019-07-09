/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:06:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 12:25:22 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int get_color(char *str, size_t pos, int *color)
{
	size_t	len;

	len = ft_strlen(str);
	if (str[pos++] != ',')
		return (0);
	if (str[pos++] != '0')
		return (0);
	if (str[pos++] != 'x')
		return (0);
	if (len - pos != 6)
		return (0);
	*color = 0;
	while (pos < len)
	{
		if ('0' <= str[pos] && str[pos] <= '9')
			*color = *color * 16 + (str[pos] - '0');
		else if ('A' <= str[pos] && str[pos] <= 'F')
			*color = *color * 16 + (str[pos] - 'A' + 10);
		else
			return (0);
		pos++;
	}
	return (1);
}

static int get_height_and_color(char *str, int *height, int *color)
{
	size_t	len;
	size_t	i;
	int		sign;

//	printf("%s ", str);
	len = ft_strlen(str);
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	*height = 0;
	while ('0' <= str[i] && str[i] <= '9')
		*height = *height * 10 + (str[i++] - '0');
	*height *= sign;
	if (i == len)
	{
		*color = 0;
		printf(" ok\n");
		return (1);
	}
	return (get_color(str, i, color));
}

static int	get_int_from_line(char *line, int **int_line, int **color)
{
	char	**heights;
	size_t	i;
	size_t	size;

//printf("Start get_int_from_line\n");
	heights = ft_strsplit(line, ' ');
	size = ft_size_of_arr(heights);
	if (!(*int_line = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free_char_arr(&heights);
		return (0);
	}
	if (!(*color = (int *)malloc(sizeof(int) * (size))))
	{
		free_char_arr(&heights);
		free(*int_line);
		return (0);
	}
	(*int_line)[0] = size;
	i = 0;
	while (i < size)
	{
		if (!get_height_and_color(heights[i], (*int_line) + i + 1, (*color) + i))
		{
			free_char_arr(&heights);
			free(*int_line);
			free(*color);
			return (0);
		}
		i++;
	}
	free_char_arr(&heights);
//	printf("Finish get_int_from_line is ok\n");
	return (1);
}

static int	get_int(char **lines, int ***int_arr, int ***colors)
{
	size_t	i;
	size_t	size;

//printf("Start get_int\n");
	if (!lines)
		return (0);
	size = ft_size_of_arr(lines);
	if (!(*int_arr = (int **)malloc(sizeof(int *) * size + 1)))
		return (0);
	if (!(*colors = (int **)malloc(sizeof(int *) * size + 1)))
	{
		free(*int_arr);
		return (0);
	}
	(*int_arr)[size] = NULL;
	(*colors)[size] = NULL;
	i = 0;
	while (lines[i])
	{
		if (!get_int_from_line(lines[i], (*int_arr) + i, (*colors) + i))
		{
			free_int_arr(int_arr);
			free_int_arr(colors);
			return (0);
		}
		i++;
	}
//printf("Finish get_int is ok\n");
	return (1);
}

static void		count_of_points(int **int_arr, int *count, int *line)
{
	int	i;

	i = 0;
	*count = 0;
	while (int_arr[i])
	{
		if (i && int_arr[i][0] != int_arr[i - 1][0])
		{
			*count = -1;
			*line = -1;
			return ;
		}
		*count += int_arr[i][0];
		*line = int_arr[i][0];
		i++;
	}
}

static t_point	*get_points_from_int(int **arr, int **color, int count)
{
	int		i;
	int		j;
	int		pos;
	t_point	*result;

	if (!(result = (t_point *)malloc(sizeof(t_point) * count)))
		return (NULL);
	pos = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (++j <= arr[i][0])
		{
			result[pos].c.x = i + 1;
			result[pos].c.y = j;
			result[pos].c.z = arr[i][j];
			v3s_mull(&result[pos].c, 10, &result[pos].c);
			result[pos].color.r = color[i][j - 1] >> 16;
			result[pos].color.g = (color[i][j - 1] >> 8) & ((1 << 8) - 1);
			result[pos].color.b = color[i][j - 1] & ((1 << 8) - 1);
			pos++;
		}
		i++;
	}
	return (result);
}

int	get_points(char *altitudes, t_mlx *displ)
{
	int		**int_arr;
	int		**color_arr;
	char	**char_arr;

	if (!(char_arr = ft_strsplit(altitudes, '\n')))
		return (0);
	if (!(get_int(char_arr, &int_arr, &color_arr)))
	{
		free_char_arr(&char_arr);
		return (0);
	}
	free_char_arr(&char_arr);
//printf("get_int is OK\n");
	count_of_points(int_arr, &(displ->count_of_points), &(displ->line_of_points));
	if (displ->count_of_points == 0 || displ->count_of_points == -1)
		return (0);
	displ->points = get_points_from_int(int_arr, color_arr, displ->count_of_points);
	free_int_arr(&int_arr);
	free_int_arr(&color_arr);
//printf("%d\n", displ->points);
	if (!displ->points)
		return (0);
	return (1);
}
