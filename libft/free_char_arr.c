/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:41:05 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/19 13:41:38 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_char_arr(char ***arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (*(*arr + i))
		ft_strdel(*arr + i++);
	free(*arr);
	*arr = NULL;
}
