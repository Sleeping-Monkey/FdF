#ifndef TMAT_H
# define TMAT_H

#include "fdf.h"

# define EPSILON 0.000001
# define R_ABS fabs
# define R_ROUND round
# define NEW(t)((t*)ft_memalloc(sizeof(t)))
# define NEW_S(t, s)((t*)ft_memalloc(sizeof(t) * s))

typedef double	t_real;
typedef struct  s_mat4
{
    t_real  r[4][4];
}               t_mat4;
typedef struct  s_vec3
{
    t_real  v[3];
}               t_vec3;

// Matrix3 ops
t_mat4          *m4_mul(t_mat4 *a, t_mat4 *b, t_mat4 *out);
t_vec3          *m4v3_mul(t_mat4 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *m4_translate(t_mat4 *a, t_vec3 *b, t_vec3 *out);
void          	m4_identity(t_mat4 *m);
int          	m4_is_identity(t_mat4 *m);
// TODO: Determinant and Inverse
//		implement this?
//		https://www.sanfoundry.com/c-program-find-inverse-matrix/
t_real          m4_det(t_mat4 *m);
t_mat4          *m4_inv(t_mat4 *m, t_mat4 *out);

// Vec3 ops
t_real          v3_mag(t_vec3 *v);
t_vec3          *v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_norm(t_vec3 *v, t_vec3 *out);
t_vec3          *v3s_mull(t_vec3 *v, t_real s, t_vec3 *out);

#endif
