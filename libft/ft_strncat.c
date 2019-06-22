/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:59:18 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/08 10:49:08 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned	i;
	size_t		j;

	i = 0;
	j = 0;
	if (n <= 0)
		return (s1);
	while (s1[i])
		i++;
	while (j < n)
		if (!s2[j])
		{
			s1[i] = s2[j];
			return (s1);
		}
		else
			s1[i++] = s2[j++];
	s1[i] = 0;
	return (s1);
}
