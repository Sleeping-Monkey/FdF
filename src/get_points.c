/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:06:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/22 16:27:52 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*get_int_from_line(char *line)
{
	char	**heights;
	int		*result;
	size_t	i;
	size_t	size;

	heights = ft_strsplit(line, ' ');
	size = ft_size_of_arr(heights);
	if (!(result = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free_char_arr(&heights);
		return (NULL);
	}
	result[0] = size;
	i = 0;
	while (i < size)
	{
		result[i + 1] = ft_atoi(heights[i]);
		i++;
	}
	return (result);
}

static int		**get_int(char **lines)
{
	size_t	i;
	size_t	size;
	int		**result;

	if (!lines)
		return (NULL);
	size = ft_size_of_arr(lines);
	if (!(result = (int **)malloc(sizeof(int *) * size + 1)))
		return (NULL);
	result[size] = NULL;
	i = 0;
	while (lines[i])
	{
		result[i] = get_int_from_line(lines[i]);
		i++;
	}
	return (result);
}

static int		count_of_points(int **int_arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (int_arr[i])
	{
		if (i && int_arr[i][0] != int_arr[i - 1][0])
			return (-1);
		count += int_arr[i][0];
		i++;
	}
	return (count);
}

static t_point	*get_points_from_int(int **arr, int count)
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
            result[pos].x = i + 1;
            result[pos].y = j;
            result[pos].z = arr[i][j];
			v3s_mull(&result[pos].c, 10, &result[pos].c);
//			result[pos].color = 0;
			pos++;
		}
		i++;
	}
	return (result);
}

t_point			*get_points(char *altitudes, int *count)
{
	int		**int_arr;
	char	**char_arr;
	t_point	*result;

	if (!(char_arr = ft_strsplit(altitudes, '\n')))
		return (NULL);
	if (!(int_arr = get_int(char_arr)))
	{
		free_char_arr(&char_arr);
		return (NULL);
	}
	free_char_arr(&char_arr);
	*count = count_of_points(int_arr);
	if (*count == -1 || *count == 0)
		return (NULL);
	result = get_points_from_int(int_arr, *count);
	free_int_arr(&int_arr);
	return (result);
}
