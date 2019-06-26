#include "fdf.h"

t_vec4          *v4_add(t_vec4 *a, t_vec4 *b, t_vec4 *out)
{
    if (!a || !b || (!out && !(out = NEW(t_vec4))))
        return (NULL);
    out->v[0] = a->v[0] + b->v[0];
    out->v[1] = a->v[1] + b->v[1];
    out->v[2] = a->v[2] + b->v[2];
    out->v[3] = a->v[3] + b->v[3];
    return (out);
}

t_vec4          *v4_sub(t_vec4 *a, t_vec4 *b, t_vec4 *out)
{
    if (!a || !b || (!out && !(out = NEW(t_vec4))))
        return (NULL);
    out->v[0] = a->v[0] - b->v[0];
    out->v[1] = a->v[1] - b->v[1];
    out->v[2] = a->v[2] - b->v[2];
    out->v[3] = a->v[3] - b->v[3];
    return (out);
}

t_vec4          *v4s_mull(t_vec4 *v, t_real s, t_vec4 *out)
{
	if (!v || (!out && !(out = NEW(t_vec4))))
		return (NULL);
	out->v[0] = v->v[0] * s;
	out->v[1] = v->v[1] * s;
	out->v[2] = v->v[2] * s;
	out->v[3] = v->v[3] * s;
	return (out);
}


/* 3 dimensions ops */

t_vec4          *v4_norm(t_vec4 *v, t_vec4 *out)
{
    t_real mag;

    if (!v || (!out && !(out = NEW(t_vec4))))
        return (NULL);
    mag = v4_mag(v);
    if (!mag)
        return (NULL);
    out->v[0] = v->v[0] / mag;
    out->v[1] = v->v[1] / mag;
    out->v[2] = v->v[2] / mag;
    return (out);
}

t_real          v4_mag(t_vec4 *v)
{
	return sqrt(
			pow(v->v[0], 2) +
			pow(v->v[1], 2) +
			pow(v->v[2], 2)
	);
}

t_vec4          *v4_cross(t_vec4 *a, t_vec4 *b, t_vec4 *out)
{
    if (!a || !b || (!out && !(out = NEW(t_vec4))))
        return (NULL);
    out->v[0] = a->v[1] * b->v[2] - a->v[2] * b->v[1];
    out->v[1] = a->v[2] * b->v[0] - a->v[0] * b->v[2];
    out->v[2] = a->v[0] * b->v[1] - a->v[1] * b->v[0];
    return (out);
}
