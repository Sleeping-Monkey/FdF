/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:36:21 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/11 12:59:22 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_of_number(int n)
{
	if (-10 < n && n < 0)
		return (2);
	if (0 <= n && n < 10)
		return (1);
	return (1 + len_of_number(n / 10));
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	size_t	i;
	int		sign;

	len = len_of_number(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = len;
	str[i--] = '\0';
	sign = 1;
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	while (i > 0)
	{
		str[i--] = '0' + sign * (n % 10);
		n /= 10;
	}
	if (sign == 1)
		str[i] = '0' + n % 10;
	return (str);
}
