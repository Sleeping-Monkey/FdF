/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:16:16 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/11 13:09:50 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sign(char c)
{
	return (c == '+' || c == '-');
}

int				ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	long long	max;

	max = 9223372036854775807;
	res = 0;
	sign = 1;
	while (*str != 0 && ft_isspace(*str))
		str++;
	if (*str != 0 && is_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str != 0 && *str >= '0' && *str <= '9')
		res = sign * (*str++ - '0');
	while (*str != 0 && *str >= '0' && *str <= '9')
		if (sign == 1 && (max - (*str - '0')) / 10 >= res)
			res = res * 10 + sign * (*str++ - '0');
		else if (sign == -1 && (-max - 1 + (*str - '0')) / 10 <= res)
			res = res * 10 + sign * (*str++ - '0');
		else
			return (sign == 1 ? -1 : 0);
	return ((int)res);
}
