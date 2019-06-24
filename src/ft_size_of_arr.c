/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_of_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:18:42 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/21 12:20:23 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		ft_size_of_arr(char **arr)
{
	size_t	size;

	size = 0;
	if (!arr)
		return (0);
	while (arr[size])
		size++;
	return (size);
}
