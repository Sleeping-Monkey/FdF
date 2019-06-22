/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:50:49 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/19 13:03:17 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrejoin(char *s1, char *s2, int flag)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (flag & 1)
		free(s1);
	if (flag & 2)
		free(s2);
	return (tmp);
}
