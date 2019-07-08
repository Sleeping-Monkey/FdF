/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:09:38 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/22 13:48:36 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define T_INC 10
#define R_INC 10
int		key_hook(int k, t_mlx *win)
{
	if (!win)
		return (1);
	printf("key_hook: %i\n", k);
	k == KEY_ESC ? exit(0):0;
	m4_translate(&win->camera_space, &VEC((k == KEY_W) * T_INC, 0, 0));
	m4_translate(&win->camera_space, &VEC(-(k == KEY_S) * T_INC, 0, 0));
	m4_translate(&win->camera_space, &VEC(0, -(k == KEY_D) * T_INC, 0));
	m4_translate(&win->camera_space, &VEC(0, (k == KEY_A) * T_INC, 0));
	m4_rotate(&win->camera_space, &VEC(0, (k == KEY_Q) * R_INC, 0));
	m4_rotate(&win->camera_space, &VEC(0, -(k == KEY_E) * R_INC, 0));
	m4_rotate(&win->camera_space, &VEC((k == KEY_R) * R_INC, 0, 0));
	m4_rotate(&win->camera_space, &VEC(-(k == KEY_T) * R_INC, 0, 0));
	m4_rotate(&win->camera_space, &VEC(0, 0, (k == KEY_Y) * R_INC));
	m4_rotate(&win->camera_space, &VEC(0, 0, -(k == KEY_U) * R_INC));
	draw(win);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_mlx *win)
{
	if (!win)
		return (1);

	if (button == 1)
	{
		reset_view(win);
		draw(win);
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
	printf("(%i, %i) - %i\n", x, y, button);
	return (1);
}

