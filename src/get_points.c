/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:06:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/14 12:23:57 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		cast_norm(char ***a, int **b, int **c)
{
	free_char_arr(a);
	free(*b);
	free(*c);
	return (0);
}

static int		get_int_from_line(char *line, int **int_line, int **color)
{
	char	**heights;
	size_t	i;
	size_t	size;

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
	i = (size_t)-1;
	while (++i < size)
		if (!get_height_and_color(heights[i], (*int_line) + i + 1, \
		(*color) + i))
			return (cast_norm(&heights, int_line, color));
	free_char_arr(&heights);
	return (1);
}

static int		get_int(char **lines, int ***int_arr, int ***colors)
{
	size_t	i;
	size_t	size;

	if (!lines)
		return (0);
	size = ft_size_of_arr(lines);
	if (!(*int_arr = (int **)malloc(sizeof(int *) * (size + 1))))
		return (0);
	if (!(*colors = (int **)malloc(sizeof(int *) * (size + 1))))
	{
		free(*int_arr);
		return (0);
	}
	(*int_arr)[size] = NULL;
	(*colors)[size] = NULL;
	i = (size_t)-1;
	while (lines[++i])
		if (!get_int_from_line(lines[i], (*int_arr) + i, (*colors) + i))
		{
			free_int_arr(int_arr);
			free_int_arr(colors);
			return (0);
		}
	return (1);
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
	i = -1;
	while (arr[++i])
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
	}
	return (result);
}

int				get_points(char *altitudes, t_mlx *win)
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
	count_of_points(int_arr, &(win->count_of_points), \
	&(win->line_of_points));
	if (win->count_of_points == 0 || win->count_of_points == -1)
		return (0);
	win->points = get_points_from_int(int_arr, color_arr, \
	win->count_of_points);
	free_int_arr(&int_arr);
	free_int_arr(&color_arr);
	if (!win->points)
		return (0);
	return (1);
}
