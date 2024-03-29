/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:27:06 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/14 12:34:07 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMAT_H
# define TMAT_H

# include "fdf.h"

# define EPSILON 0.000001
# define R_ABS fabs
# define R_ROUND round
# define TO_RAD(a)((a)*(M_PI / 180.0))

typedef double	t_real;
typedef struct	s_mat4
{
	t_real	r[4][4];
}				t_mat4;
typedef struct	s_vec3
{
	t_real	x;
	t_real	y;
	t_real	z;
}				t_vec3;
# define VEC(x, y, z)((t_vec3){x, y, z})

/*
** Matrix3 ops
*/
t_mat4			*m4_mul(t_mat4 *a, t_mat4 *b, t_mat4 *out);
t_vec3			*m4v3_mul(t_mat4 *a, t_vec3 *b, t_vec3 *out);
t_mat4			*m4_identity(t_mat4 *m);
int				m4_is_identity(t_mat4 *m);
t_mat4			*m4_copy(t_mat4 *m, t_mat4 *out);
void			m4_translate(t_mat4 *m, t_vec3 *t);
void			m4_rotate(t_mat4 *m, t_vec3 *r);
void			m4_set_rotation(t_mat4 *m, t_vec3 *r);
void			m4_scale(t_mat4 *m, t_vec3 *s);
void			m4_set_translate(t_mat4 *m, t_vec3 *t);
t_vec3			*m4_extract_translation(t_mat4 *m, t_vec3 *out);
t_vec3			*m4_extract_scale(t_mat4 *m, t_vec3 *out);
t_mat4			*m4_extract_rotation(t_mat4 *m, t_mat4 *out);
void			m4_rotate_relative(t_mat4 *m, t_vec3 *p, t_vec3 *rot);

/*
** TODO: Determinant and Inverse
**		implement this?
**		https://www.sanfoundry.com/c-program-find-inverse-matrix/
*/
t_real			m4_det(t_mat4 *m);
t_mat4			*m4_inv(t_mat4 *m, t_mat4 *out);

/*
** Vec3 ops
*/
t_real			v3_mag(t_vec3 *v);
t_vec3			*v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3			*v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3			*v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3			*v3_norm(t_vec3 *v, t_vec3 *out);
t_vec3			*v3s_mull(t_vec3 *v, t_real s, t_vec3 *out);
t_vec3			*v3_copy(t_vec3 *v, t_vec3 *out);

#endif
