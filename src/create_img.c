/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:36:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/14 12:27:53 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned	get_real_color(t_point *pos, t_mlx *win)
{
	double	h_min;
	double	h_max;
	t_vec3	tmp_pos;
	t_color a[10];

	m4v3_mul(&win->camera_space, &pos->c, &tmp_pos);
	h_min = win->left.z;
	h_max = win->right.z;
	if (tmp_pos.z >= 0)
	{
		a[0] = (tmp_pos.z / h_max >= 0.5) ? COLOR(255, 0, 0) : COLOR(0, 255, 0);
		a[1] = (tmp_pos.z / h_max >= 0.5) ? COLOR(255, 255, 0) : \
		COLOR(0, 100, 142);
	}
	else
	{
		a[0] = (tmp_pos.z / h_min > -0.5) ? COLOR(0, 0, 255) : COLOR(0, 255, 0);
		a[1] = (tmp_pos.z / h_min > -0.5) ? COLOR(0, 255, 0) : \
		COLOR(0, 100, 142);
	}
	a[2] = COLOR(a[0].r + (a[1].r - a[0].r) * (tmp_pos.z / h_max), \
	a[0].g + (a[1].g - a[0].g) * (tmp_pos.z / h_max), \
	a[0].b + (a[1].b - a[0].b) * (tmp_pos.z / h_max));
	return (PACK_COLOR(a[2]));
}

static void		set_pnt_to_img(t_point *pos, t_mlx *win)
{
	unsigned	color;

	color = (win->real ? get_real_color(pos, win) : (((pos->color.r << 8) + \
	pos->color.g) << 8) + pos->color.b);
	if (pos->c.x > 0 && pos->c.x < win->img.size_x && pos->c.y > 0 && \
	pos->c.y < win->img.size_y)
		win->img.pic[(size_t)(win->img.size_y * (int)(pos->c.x) + \
		(int)(pos->c.y))] = color;
}

static unsigned	ft_max(unsigned a, unsigned b, unsigned c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}

static void		set_line_to_img(t_point *a, t_point *b, t_mlx *win)
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
		set_pnt_to_img(&c, win);
		v3_add(&c.c, &d, &c.c);
		c.color.r += dc.r;
		c.color.g += dc.g;
		c.color.b += dc.b;
		set_pnt_to_img(&c, win);
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
			set_line_to_img(&a, &b, win);
		}
		if (i + win->line_of_points < win->count_of_points)
		{
			b = win->points[i + win->line_of_points];
			m4v3_mul(&inv, &b.c, &b.c);
			set_line_to_img(&a, &b, win);
		}
		i++;
	}
}
