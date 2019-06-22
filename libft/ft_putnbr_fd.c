/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:23:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/05 12:58:07 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (fd < 0)
		return ;
	sign = 1;
	if (n < 0)
		sign = -1;
	if (-10 < n && n < 0)
		ft_putchar_fd('-', fd);
	if (-10 < n && n < 10)
		ft_putchar_fd('0' + sign * n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + sign * (n % 10), fd);
	}
}
