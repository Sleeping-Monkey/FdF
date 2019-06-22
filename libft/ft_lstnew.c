/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:57:49 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/06 16:13:29 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		new_elem->content = NULL;
		content_size = 0;
	}
	else
	{
		new_elem->content = malloc(content_size);
		if (new_elem->content == NULL)
		{
			free(new_elem);
			return (NULL);
		}
		new_elem->content = ft_memcpy(new_elem->content, content, content_size);
	}
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
