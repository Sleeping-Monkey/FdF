/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:49:54 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/02 17:42:50 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;
	int				flag;

	flag = *src != 0;
	i = 0;
	while (i < len)
	{
		if (flag)
			dst[i] = src[i];
		else
			dst[i] = 0;
		if (flag && src[i] == 0)
			flag = 0;
		i++;
	}
	return (dst);
}
