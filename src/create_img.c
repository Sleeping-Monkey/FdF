/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:36:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 11:54:20 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_pnt_to_img(t_point *pos, t_img *img)
{
	//printf("set_pnt: (%f, %f, %f)\n", pos->c.x, pos->c.y, pos->c.z);
	unsigned	color;

	color = (((pos->color.r << 8) + pos->color.g) << 8) + pos->color.b; 
	if (pos->c.x > 0 && pos->c.x < img->size_x && pos->c.y > 0 && pos->c.y < img->size_y)
		img->pic[(size_t)(img->size_y * (int)(pos->c.x) + (int)(pos->c.y))] = color;
}

static void	set_line_to_img(t_point *a, t_point *b, t_img *img)
{
	t_point	c;
	t_vec3	d;

	d = VEC(b->c.x - a->c.x, b->c.y - a->c.y, b->c.z - a->c.z);
	v3_norm(&d, &d);
	c.c = VEC(a->c.x, a->c.y, a->c.z);
	c.color = a->color;
	// printf("%i %i %i", (int)dx, (int)dy, (int)dz);
	while (fabs(c.c.x - b->c.x) > 1 || fabs(c.c.y - b->c.y) > 1 || \
	fabs(c.c.z - b->c.z) > 1)
	{
		set_pnt_to_img(&c, img);
		v3_add(&c.c, &d, &c.c);
		set_pnt_to_img(&c, img);
	}
}

void		create_img(t_mlx *win)
{
	int		i;
	t_mat4	inv;
	t_point a;
	t_point b;

	// Get camera inverse matrix to project points
	m4_inv(&win->camera_space, &inv);
	i = 0;
	while (i < win->count_of_points - 1)
	{
		a = win->points[i];
		// Project point A
		m4v3_mul(&inv, &a.c, &a.c);
		if ((i + 1) % win->line_of_points != 0)
		{
			b = win->points[i + 1];
			// Project point B
			m4v3_mul(&inv, &b.c, &b.c);
			set_line_to_img(&a, &b, &win->img);
		}
		if (i + win->line_of_points < win->count_of_points)
		{
			b = win->points[i + win->line_of_points];
			// Project point B
			m4v3_mul(&inv, &b.c, &b.c);
			set_line_to_img(&a, &b, &win->img);
		}
		i++;
	}
}
