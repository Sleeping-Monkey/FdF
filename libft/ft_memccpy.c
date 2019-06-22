/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:59:00 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/08 10:43:25 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (i == 0 || *(((unsigned char *)src) + i - 1) != (unsigned char)c)
		{
			*(((unsigned char *)dst) + i) = *(((unsigned char *)src) + i);
			i++;
		}
		else
			break ;
	}
	if (i == 0 || *(((unsigned char *)src) + i - 1) != (unsigned char)c)
		return (NULL);
	return (dst + i);
}
