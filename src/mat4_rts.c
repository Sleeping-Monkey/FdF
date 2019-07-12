/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:33:58 by bnesoi            #+#    #+#             */
/*   Updated: 2019/07/09 15:09:06 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3			*m4_get_translation(t_mat4 *m, t_vec3 *out)
{
	if (!m || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->x = m->r[3][0];
	out->y = m->r[3][1];
	out->z = m->r[3][2];
	return (out);
}

t_vec3			*m4_get_scale(t_mat4 *m, t_vec3 *out)
{
	if (!m || (!out && !(out = NEW(t_vec3))))
		return (NULL);
	out->x = v3_mag((t_vec3 *) m->r[0]);
	out->y = v3_mag((t_vec3 *) m->r[1]);
	out->z = v3_mag((t_vec3 *) m->r[2]);
	return (out);
}
