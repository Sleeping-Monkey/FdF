/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:50:15 by ssheba            #+#    #+#             */
/*   Updated: 2019/04/11 13:06:44 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_spaces(char const *s, int *b, int *e)
{
	*e = ft_strlen(s) - 1;
	*b = 0;
	while (s[*b] && (s[*b] == ' ' || s[*b] == '\t' || s[*b] == '\n'))
		(*b)++;
	while (*e >= 0 && (s[*e] == ' ' || s[*e] == '\n' || s[*e] == '\t'))
		(*e)--;
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		end;
	int		begin;
	int		i;

	if (s == NULL)
		return (NULL);
	end = 0;
	begin = 0;
	skip_spaces(s, &begin, &end);
	if (end < begin)
		begin = end + 1;
	str = (char *)malloc(sizeof(char) * (end - begin + 1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (begin + i <= end)
	{
		str[i] = s[begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
