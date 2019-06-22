/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:58:12 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/06 11:02:10 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (c == '\0')
		return ((char *)s + len);
	i = len - 1;
	while (i >= 0 && s[i] != c)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)s + i);
}
