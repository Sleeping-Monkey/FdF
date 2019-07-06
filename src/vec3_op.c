/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:46:28 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/06 14:46:28 by bnesoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	*v3_norm(t_vec3 *v, t_vec3 *out)
{
	t_real mag;

	if (!v || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	mag = v3_mag(v);
	if (!mag)
		return (NULL);
	out->v[0] = v->v[0] / mag;
	out->v[1] = v->v[1] / mag;
	out->v[2] = v->v[2] / mag;
	return (out);
}

t_real	v3_mag(t_vec3 *v)
{
	return (sqrt(
			pow(v->v[0], 2) +
			pow(v->v[1], 2) +
			pow(v->v[2], 2)));
}

t_vec3	*v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->v[0] = a->v[1] * b->v[2] - a->v[2] * b->v[1];
	out->v[1] = a->v[2] * b->v[0] - a->v[0] * b->v[2];
	out->v[2] = a->v[0] * b->v[1] - a->v[1] * b->v[0];
	return (out);
}
