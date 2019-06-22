/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:27:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/05 19:08:22 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == n)
		return (0);
	return ((int)(*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i)));
}
