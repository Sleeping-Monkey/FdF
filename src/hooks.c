/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:09:38 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/11 17:41:15 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define T_INC 10
#define R_INC 10

int		key_hook(int k, t_mlx *win)
{
	t_mat4 *m;
	t_vec3 *p;

	if (!win)
		return (1);

	m = &win->camera_space;
	p = &win->center;
	k == KEY_ESC ? finish(win) : 0;
	k == KEY_Q ? m4_rotate_relative(m, p, &VEC(0, R_INC, 0)) : 0;
	k == KEY_E ? m4_rotate_relative(m, p, &VEC(0, -R_INC, 0)) : 0;
	k == KEY_T ? m4_rotate_relative(m, p, &VEC(R_INC, 0, 0)) : 0;
	k == KEY_R ? m4_rotate_relative(m, p, &VEC(-R_INC, 0, 0)) : 0;
	k == KEY_Y ? m4_rotate_relative(m, p, &VEC(0, 0, R_INC)) : 0;
	k == KEY_U ? m4_rotate_relative(m, p, &VEC(0, 0, -R_INC)) : 0;

	k == KEY_W ? m4_translate(m, &VEC(T_INC, 0, 0)) : 0;
	k == KEY_S ? m4_translate(m, &VEC(-T_INC, 0, 0)) : 0;
	k == KEY_D ? m4_translate(m, &VEC(0, -T_INC, 0)) : 0;
	k == KEY_A ? m4_translate(m, &VEC(0, T_INC, 0)) : 0;
	k == KEY_V ? reset_view(win) : 0;
	draw(win);
	return (1);
}

int		mouse_press(int button, int x, int y, t_mlx *win)
{
	printf("press: (%d, %d) - %d\n", x, y, button);
	if (!win)
		return (1);
	if (button == 2)
	{
		reset_view(win);
		draw(win);
	}
	else if (button == 1)
	{
		win->mouse_flag = 1;
		win->mouse_x = x;
		win->mouse_y = y;
	}
	else if (button == 4)
	{
		m4_scale(&win->camera_space, &VEC(.95, .95, 1));
		draw(win);
	}
	else if (button == 5)
	{
		m4_scale(&win->camera_space, &VEC(1.1, 1.1, 1));
		draw(win);
	}
	return (1);
}

int		mouse_release(int button, int x, int y, t_mlx *win)
{
	printf("release: (%d, %d) - %d\n", x, y, button);
	if (button == 1)
		if (win->mouse_flag)
		{
			m4_rotate(&win->camera_space, &VEC(x - win->mouse_x, y - win->mouse_y, 0));
			win->mouse_flag = 0;
			draw(win);
		}
	return (1);
}

int 	mouse_move(int x, int y, t_mlx *win)
{
	printf("move: (%d, %d) - 0\n", x, y);
//	(void)win;
	if (win->mouse_flag)
	{
		m4_rotate(&win->camera_space, &VEC(x - win->mouse_x, y - win->mouse_y, 0));
		win->mouse_x = x;
		win->mouse_y = y;
		draw(win);
	}
	return (1);
}
