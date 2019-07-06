/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:33:58 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/06 14:36:56 by bnesoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	m4_translate(t_mat4 *m, t_vec3 *t)
{
	m->r[3][0] +=
			t->v[0] * m->r[0][0] +
			t->v[1] * m->r[1][0] +
			t->v[2] * m->r[2][0];
	m->r[3][1] +=
			t->v[0] * m->r[0][1] +
			t->v[1] * m->r[1][1] +
			t->v[2] * m->r[2][1];
	m->r[3][2] +=
			t->v[0] * m->r[0][2] +
			t->v[1] * m->r[1][2] +
			t->v[2] * m->r[2][2];
	m->r[3][3] +=
			t->v[0] * m->r[0][3] +
			t->v[1] * m->r[1][3] +
			t->v[2] * m->r[2][3];
}

void	m4_set_rotation(t_mat4 *m, t_vec3 *r)
{
	t_real	cos_v[3];
	t_real	sin_v[3];

	m4_identity(m);
	cos_v[2] = cos(TO_RAD(r->v[2]));
	cos_v[1] = cos(TO_RAD(r->v[1]));
	cos_v[0] = cos(TO_RAD(r->v[0]));
	sin_v[2] = sin(TO_RAD(r->v[2]));
	sin_v[1] = sin(TO_RAD(r->v[1]));
	sin_v[0] = sin(TO_RAD(r->v[0]));
	m->r[0][0] = cos_v[2] * cos_v[1];
	m->r[0][1] = sin_v[2] * cos_v[1];
	m->r[0][2] = -sin_v[1];
	m->r[1][0] = -sin_v[2] * cos_v[0] + cos_v[2] * sin_v[1] * sin_v[0];
	m->r[1][1] = cos_v[2] * cos_v[0] + sin_v[2] * sin_v[1] * sin_v[0];
	m->r[1][2] = cos_v[1] * sin_v[0];
	m->r[2][0] = -sin_v[2] * -sin_v[0] + cos_v[2] * sin_v[1] * cos_v[0];
	m->r[2][1] = cos_v[2] * -sin_v[0] + sin_v[2] * sin_v[1] * cos_v[0];
	m->r[2][2] = cos_v[1] * cos_v[0];
}

void	m4_rotate(t_mat4 *m, t_vec3 *r)
{
	t_mat4	mr;
	t_mat4	mc;
	int		rr;
	int		cc;
	int		k;

	mc = *m4_copy(m, &mc);
	m4_set_rotation(&mr, r);
	rr = 3;
	while (rr--)
	{
		cc = 4;
		while (cc--)
		{
			k = 3;
			m->r[rr][cc] = 0;
			while (k--)
				if (mc.r[rr][k])
					m->r[rr][cc] += mc.r[rr][k] * mr.r[k][cc];
		}
	}
}

void	m4_scale(t_mat4 *m, t_vec3 *s)
{
	int r;
	int c;

	r = 3;
	while (r--)
	{
		c = 3;
		while (c--)
			m->r[r][c] *= s->v[r];
	}
}
