#include "fdf.h"

void			m4_translate(t_mat4 *m, t_vec3 *t)
{
	m->r[3][0] += t->v[0] * m->r[0][0] + t->v[1] * m->r[1][0] + t->v[2] * m->r[2][0];
	m->r[3][1] += t->v[0] * m->r[0][1] + t->v[1] * m->r[1][1] + t->v[2] * m->r[2][1];
	m->r[3][2] += t->v[0] * m->r[0][2] + t->v[1] * m->r[1][2] + t->v[2] * m->r[2][2];
	m->r[3][3] += t->v[0] * m->r[0][3] + t->v[1] * m->r[1][3] + t->v[2] * m->r[2][3];
}

void			m4_setRotation(t_mat4 *m, t_vec3 *r)
{
	t_real cos_rz;
	t_real cos_ry;
	t_real cos_rx;
	t_real sin_rz;
	t_real sin_ry;
	t_real sin_rx;

	m4_identity(m);
	cos_rz = cos(TO_RAD(r->v[2]));
	cos_ry = cos(TO_RAD(r->v[1]));
	cos_rx = cos(TO_RAD(r->v[0]));
	sin_rz = sin(TO_RAD(r->v[2]));
	sin_ry = sin(TO_RAD(r->v[1]));
	sin_rx = sin(TO_RAD(r->v[0]));
	m->r[0][0] = cos_rz * cos_ry;
	m->r[0][1] = sin_rz * cos_ry;
	m->r[0][2] = -sin_ry;
	m->r[1][0] = -sin_rz * cos_rx + cos_rz * sin_ry * sin_rx;
	m->r[1][1] = cos_rz * cos_rx + sin_rz * sin_ry * sin_rx;
	m->r[1][2] = cos_ry * sin_rx;
	m->r[2][0] = -sin_rz * -sin_rx + cos_rz * sin_ry * cos_rx;
	m->r[2][1] = cos_rz * -sin_rx + sin_rz * sin_ry * cos_rx;
	m->r[2][2] = cos_ry * cos_rx;
}

void			m4_rotate(t_mat4 *m, t_vec3 *r)
{
	t_mat4	mr;
	t_mat4	mc;
	int		rr;
	int		cc;
	int		k;

	mc = *m4_copy(m, &mc);
	m4_setRotation(&mr, r);

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

void			m4_scale(t_mat4 *m, t_vec3 *s)
{
	int r;
	int c;

	r = 3;
	while(r--)
	{
		c = 3;
		while(c--)
			m->r[r][c] *= s->v[r];
	}
}
