#ifndef TMAT_H
# define TMAT_H

#include "fdf.h"

typedef double	t_real;
#define EPSILON 0.000001
#define R_ABS fabs
#define R_ROUND round

typedef struct	s_vec
{
	int	n;
	t_real *e;
}				t_vec;

typedef struct	s_mat
{
	int	m;
	int	n;
	t_real **r;
	t_real *e;
}				t_mat;

typedef struct  s_mat4
{
    t_real  r[4][4];
}               t_mat4;

typedef struct  s_vec4
{
    t_real  v[4];
}               t_vec4;

#define NEW(t)((t*)ft_memalloc(sizeof(t)))
#define NEW_S(t, s)((t*)ft_memalloc(sizeof(t) * s))
#define SIZ_R(n)((sizeof(t_real) * n))
#define REAL(n, ...)((t_real[n]){__VA_ARGS__})
#define M3_SET(m, ...)(ft_memcpy((m)->e, &REAL(9, __VA_ARGS__), SIZ_R(9)))
#define V3_SET(v, ...)(ft_memcpy((v)->e, &REAL(3, __VA_ARGS__), SIZ_R(3)))
#define M4_SET(m, ...)(ft_memcpy((m)->e, &REAL(16, __VA_ARGS__), SIZ_R(16)))
#define V4_SET(v, ...)(ft_memcpy((v)->e, &REAL(4, __VA_ARGS__), SIZ_R(4)))
/* ************************************************************************** */

// Matrix ops
t_mat			*m_mul(t_mat *a, t_mat *b, t_mat *out);
void			m_identity(t_mat *m);
t_vec			*mv_mul(t_mat *m, t_vec *v, t_vec *out);
t_vec			*sm_mul(t_mat *m, t_real s, t_vec *out);

// Matrix3 ops
t_mat4          *m4_mul(t_mat4 *a, t_mat4 *b, t_mat4 *out);
t_vec4          *m4v4_mul(t_mat4 *a, t_vec4 *b, t_vec4 *out);
void          	m4_identity(t_mat4 *m);
int          	m4_is_identity(t_mat4 *m);

// TODO: Determinant and Inverse
//		implement this?
//		https://www.sanfoundry.com/c-program-find-inverse-matrix/
t_real          m4_det(t_mat4 *m);
t_mat4          *m4_inv(t_mat4 *m, t_mat4 *out);

// Vec3 ops
t_real          v4_mag(t_vec4 *v);
t_vec4          *v4_add(t_vec4 *a, t_vec4 *b, t_vec4 *out);
t_vec4          *v4_sub(t_vec4 *a, t_vec4 *b, t_vec4 *out);
t_vec4          *v4_cross(t_vec4 *a, t_vec4 *b, t_vec4 *out);
t_vec4          *v4_norm(t_vec4 *v, t_vec4 *out);
t_vec4          *v4s_mull(t_vec4 *v, t_real s, t_vec4 *out);

// Utils
t_mat			*m_get(int m, int n);
t_vec			*v_get(int n);
void			m_free(t_mat **m);
void			v_free(t_vec **m);

#endif
