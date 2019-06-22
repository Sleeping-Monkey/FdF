/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:45:25 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/06 13:36:37 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	**ptr;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = &new_list;
	while (lst)
	{
		*ptr = f(lst);
		if (*ptr == NULL)
			return (NULL);
		ptr = &(*ptr)->next;
		lst = lst->next;
	}
	return (new_list);
}
