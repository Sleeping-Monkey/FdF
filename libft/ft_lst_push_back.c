/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:14:19 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/12 16:28:49 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	while (*alst != NULL)
		alst = &(*alst)->next;
	*alst = new;
}
