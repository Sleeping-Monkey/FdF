/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:55:38 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/10 13:56:03 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_of_points(int **int_arr, int *count, int *line)
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
