/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:06:46 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/14 16:36:45 by bnesoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			fill_win(t_mlx *win, t_color *color)
{
	size_t	i;
	int		c;

	i = win->img.size_x * win->img.size_y;
	c = (int)((unsigned)((color->r << 8u) + color->g) << 8u) + color->b;
	while (i--)
		win->img.pic[i] = c;
}

static void		update_view_bb(t_vec3 *screen_left,
	t_vec3 *screen_right, t_mlx *win)
{
	int		i;
	t_mat4	inv;
	t_vec3	p;

	m4_inv(&win->camera_space, &inv);
	i = 0;
	while (i < win->count_of_points - 1)
	{
		p = win->points[i].c;
		m4v3_mul(&inv, &p, &p);
		screen_left->x > p.x || !i ? screen_left->x = p.x : 0;
		screen_left->y > p.y || !i ? screen_left->y = p.y : 0;
		screen_right->x < p.x ? screen_right->x = p.x : 0;
		screen_right->y < p.y ? screen_right->y = p.y : 0;
		i++;
	}
}

void			draw(t_mlx *win)
{
	fill_win(win, &COLOR(255, 255, 255));
	create_img(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}

void			fit_view(t_mlx *win)
{
	t_real x;
	t_real y;
	t_real s;
	t_vec3 screen_left;
	t_vec3 screen_right;

	screen_left = VEC(0, 0, 0);
	screen_right = VEC(0, 0, 0);
	update_view_bb(&screen_left, &screen_right, win);
	m4_translate(&win->camera_space,
		&VEC(screen_left.x, screen_left.y, 0));
	x = screen_right.x - screen_left.x;
	y = screen_right.y - screen_left.y;
	if (x < y)
		s = y;
	else
		s = x;
	m4_scale(&win->camera_space,
		&VEC(s / win->img.size_x, s / win->img.size_y, 1));
}

void			reset_view(t_mlx *win, t_vec3 *r)
{
	m4_identity(&win->camera_space);
	m4_rotate(&win->camera_space, r);
	fit_view(win);
}
