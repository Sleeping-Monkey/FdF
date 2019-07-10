/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height_and_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:58:00 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/10 14:07:27 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_color(char *str, size_t pos, int *color)
{
	size_t	len;

	len = ft_strlen(str);
	if (str[pos++] != ',')
		return (0);
	if (str[pos++] != '0')
		return (0);
	if (str[pos++] != 'x')
		return (0);
	if (len - pos != 6)
		return (0);
	*color = 0;
	while (pos < len)
	{
		if ('0' <= str[pos] && str[pos] <= '9')
			*color = *color * 16 + (str[pos] - '0');
		else if ('A' <= str[pos] && str[pos] <= 'F')
			*color = *color * 16 + (str[pos] - 'A' + 10);
		else
			return (0);
		pos++;
	}
	return (1);
}

int			get_height_and_color(char *str, int *height, int *color)
{
	size_t	len;
	size_t	i;
	int		sign;

	len = ft_strlen(str);
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	*height = 0;
	while ('0' <= str[i] && str[i] <= '9')
		*height = *height * 10 + (str[i++] - '0');
	*height *= sign;
	if (i == len)
	{
		*color = 0;
		return (1);
	}
	return (get_color(str, i, color));
}
