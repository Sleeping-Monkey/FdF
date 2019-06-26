#ifndef TMAT_H
# define TMAT_H

#include "fdf.h"

typedef double	t_real;

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

typedef struct  s_mat3
{
    t_real  r[3][3];
}               t_mat3;

typedef struct  s_vec3
{
    t_real  v[3];
}               t_vec3;

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
t_mat3          *m3_mul(t_mat3 *a, t_mat3 *b, t_mat3 *out);
t_vec3          *m3v3_mul(t_mat3 *a, t_vec3 *b, t_vec3 *out);
void          	m3_identity(t_mat3 *m);

// TODO: Determinant and Inverse
t_real          m3_det(t_mat3 *m);
t_mat3          *m3_inv(t_mat3 *m, t_mat3 *out);

// Vec3 ops
t_real          v3_mag(t_vec3 *v);
t_vec3          *v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3          *v3_norm(t_vec3 *v, t_vec3 *out);
t_vec3          *v3s_mull(t_vec3 *v, t_real s, t_vec3 *out);

// Utils
t_mat			*m_get(int m, int n);
t_vec			*v_get(int n);
void			m_free(t_mat **m);
void			v_free(t_vec **m);

#endif
