/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:36:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/13 16:49:26 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned	get_real_color(t_point *pos, t_mlx *win, t_mat4 *inv)
{
	double	h_min;
	double	h_max;
	t_vec3	tmp_pos;
	t_vec3	tmp;

	m4v3_mul(&win->camera_space, &pos->c, &tmp_pos);
//	m4v3_mul(&win->camera_space, &win->left, &tmp);
//	m4v3_mul(&win->camera_space, &win->right, &tmp);
    (void)inv;
	tmp = win->right;
	h_min = tmp.z;
	h_max = tmp.z;
	if (tmp_pos.z > h_max * 0.9)
		return ((((255 << 8) + 246) << 8) + 134);
	if (tmp_pos.z > h_max * 0.7)
		return ((((234 << 8) + 187) << 8) + 40);
	if (tmp_pos.z > h_max * 0.4)
		return ((((207 << 8) + 131) << 8) + 20);
	if (tmp_pos.z > h_max * 0.2)
		return ((((45 << 8) + 173) << 8) + 14);
	if (tmp_pos.z >= 0)
		return ((((45 << 8) + 226) << 8) + 0);
	if (tmp_pos.z < h_min * 0.9)
		return ((((7 << 8) + 63) << 8) + 155);
	if (tmp_pos.z < h_min * 0.7)
		return ((((7 << 8) + 116) << 8) + 155);
	if (tmp_pos.z < h_min * 0.4)
		return ((((0 << 8) + 167) << 8) + 160);
	if (tmp_pos.z < h_min * 0.2)
		return ((((0 << 8) + 226) << 8) + 168);
	return ((((59 << 8) + 245) << 8) + 194);
}

static void		set_pnt_to_img(t_point *pos, t_mlx *win, t_mat4 *inv)
{
	unsigned	color;

	color = (win->real ? get_real_color(pos, win, inv) : (((pos->color.r << 8) + \
	pos->color.g) << 8) + pos->color.b);
	if (pos->c.x > 0 && pos->c.x < win->img.size_x && pos->c.y > 0 && \
	pos->c.y < win->img.size_y)
		win->img.pic[(size_t)(win->img.size_y * (int)(pos->c.x) + (int)(pos->c.y))] = \
		color;
}

static unsigned	ft_max(unsigned a, unsigned b, unsigned c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}

static void		set_line_to_img(t_point *a, t_point *b, t_mlx *win, t_mat4 *inv)
{
	t_point		c;
	t_vec3		d;
	t_color		dc;
	unsigned	steps;

	d = VEC(b->c.x - a->c.x, b->c.y - a->c.y, b->c.z - a->c.z);
	v3_norm(&d, &d);
	c.c = VEC(a->c.x, a->c.y, a->c.z);
	c.color = a->color;
	steps = ft_max((unsigned)((b->c.x - a->c.x) / d.x), \
	(unsigned)((b->c.y - a->c.y) / d.y), (unsigned)((b->c.z - a->c.z) / d.z));
	dc.r = (b->color.r - a->color.r) / steps;
	dc.g = (b->color.g - a->color.g) / steps;
	dc.b = (b->color.b - a->color.b) / steps;
	while (R_ABS(c.c.x - b->c.x) > 1 || R_ABS(c.c.y - b->c.y) > 1 || \
	R_ABS(c.c.z - b->c.z) > 1)
	{
		set_pnt_to_img(&c, win, inv);
		v3_add(&c.c, &d, &c.c);
		c.color.r += dc.r;
		c.color.g += dc.g;
		c.color.b += dc.b;
		set_pnt_to_img(&c, win, inv);
	}
}

void			create_img(t_mlx *win)
{
	int		i;
	t_mat4	inv;
	t_point a;
	t_point b;

	m4_inv(&win->camera_space, &inv);
	i = 0;
	while (i < win->count_of_points - 1)
	{
		a = win->points[i];
		m4v3_mul(&inv, &a.c, &a.c);
		if ((i + 1) % win->line_of_points != 0)
		{
			b = win->points[i + 1];
			m4v3_mul(&inv, &b.c, &b.c);
			set_line_to_img(&a, &b, win, &inv);
		}
		if (i + win->line_of_points < win->count_of_points)
		{
			b = win->points[i + win->line_of_points];
			m4v3_mul(&inv, &b.c, &b.c);
			set_line_to_img(&a, &b, win, &inv);
		}
		i++;
	}
}
