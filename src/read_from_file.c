/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:37:55 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/19 13:04:05 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
	{
		if (errno == EISDIR)
			return (fd);
		else
			fd = open(file_name, O_RDONLY);
	}
	return (fd);
}

char			*read_from_file(char *file_name)
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	size_t	pos;
	char	*result;

	if ((fd = open_file(file_name)) < 0)
		return (NULL);
	result = ft_strnew(0);
	while ((pos = read(fd, buff, BUFF_SIZE)))
	{
		buff[pos] = 0;
		if (!(result = ft_strrejoin(result, buff, 1)))
			return (NULL);
	}
	return (result);
}
