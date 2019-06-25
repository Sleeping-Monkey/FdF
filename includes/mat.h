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

#define NEW(t)((t*)ft_memalloc(sizeof(t)))
#define NEW_S(t, s)((t*)ft_memalloc(sizeof(t) * s))
#define SIZ_R(n)((sizeof(t_real) * n))
#define M_SET3(m, ...)(ft_memcpy((m)->e, &(t_real[9]){__VA_ARGS__}, SIZ_R(9)))
#define V_SET3(v, ...)(ft_memcpy((v)->e, &(t_real[3]){__VA_ARGS__}, SIZ_R(3)))
#define M_SET4(m, ...)(ft_memcpy((m)->e, &(t_real[16]){__VA_ARGS__}, SIZ_R(16)))
#define V_SET4(v, ...)(ft_memcpy((v)->e, &(t_real[4]){__VA_ARGS__}, SIZ_R(4)))
/* ************************************************************************** */

// Matrix ops
t_mat			*m_mul(t_mat *a, t_mat *b, t_mat *out);
void			m_identity(t_mat *m);
t_vec			*mv_mul(t_mat *m, t_vec *v, t_vec *out);
t_vec			*sm_mul(t_mat *m, t_real s, t_vec *out);

// Vector ops
t_vec			*v_sub(t_vec *a, t_vec *b, t_vec *out);
t_vec			*v_add(t_vec *a, t_vec *b, t_vec *out);
t_vec			*v_mul(t_vec *a, t_vec *b, t_vec *out);
t_vec			*sv_sub(t_vec *a, t_real s, t_vec *out);
t_vec			*sv_add(t_vec *a, t_real s, t_vec *out);
t_vec			*sv_mul(t_vec *a, t_real s, t_vec *out);
t_real			v_mag(t_vec *v);
t_vec			*v_norm(t_vec *v, t_vec *out);

// Utils
t_mat			*m_get(int m, int n);
t_vec			*v_get(int n);
void			m_free(t_mat **m);
void			v_free(t_vec **m);

#endif
