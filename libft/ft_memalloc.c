/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:11:47 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/11 13:00:36 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	if (size == 0)
		return (NULL);
	res = malloc(size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		*((unsigned char *)res + i++) = 0;
	return (res);
}
