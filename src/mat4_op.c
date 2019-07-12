/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:33:58 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/09 15:09:06 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	m4_rotate_relative(t_mat4 *m, t_vec3 *p, t_vec3 *rot)
{
	t_mat4	inv_rel;
	t_mat4	m_rot;

	m4_set_translate(&m_rot, p);
	m4_mul(m, m4_inv(&m_rot, &inv_rel), m);
	m4_rotate(&m_rot, rot);
	m4_mul(m, &m_rot, m);
}
