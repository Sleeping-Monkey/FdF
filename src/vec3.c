/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:43:24 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/06 14:48:45 by bnesoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	*v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->v[0] = a->v[0] + b->v[0];
	out->v[1] = a->v[1] + b->v[1];
	out->v[2] = a->v[2] + b->v[2];
	return (out);
}

t_vec3	*v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->v[0] = a->v[0] - b->v[0];
	out->v[1] = a->v[1] - b->v[1];
	out->v[2] = a->v[2] - b->v[2];
	return (out);
}

t_vec3	*v3s_mull(t_vec3 *v, t_real s, t_vec3 *out)
{
	if (!v || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->v[0] = v->v[0] * s;
	out->v[1] = v->v[1] * s;
	out->v[2] = v->v[2] * s;
	return (out);
}

t_vec3			*v3_copy(t_vec3 *v, t_vec3 *out)
{
	if (!v)
		return (NULL);
	if ((!out && !(out = NEW(t_vec3))))
		return (NULL);
	ft_memmove(out, v, sizeof(t_vec3));
	return (out);
}
