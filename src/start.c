/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:47:14 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/13 14:29:42 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_bounding_box(t_mlx *win)
{
	int	i;

	i = 0;
	win->left = VEC(win->points[0].c.x, win->points[0].c.y, \
	win->points[0].c.z);
	win->right = VEC(win->points[0].c.x, win->points[0].c.y, \
	win->points[0].c.z);
	while (++i < win->count_of_points)
	{
		if (win->left.x > win->points[i].c.x)
			win->left.x = win->points[i].c.x;
		if (win->left.y > win->points[i].c.y)
			win->left.y = win->points[i].c.y;
		if (win->left.z > win->points[i].c.z)
			win->left.z = win->points[i].c.z;
		if (win->right.x < win->points[i].c.x)
			win->right.x = win->points[i].c.x;
		if (win->right.y < win->points[i].c.y)
			win->right.y = win->points[i].c.y;
		if (win->right.z < win->points[i].c.z)
			win->right.z = win->points[i].c.z;
	}
	v3s_mull(&win->right, 0.5, &win->center);
}

static int	init_points(t_mlx *win, char *file_name)
{
	char	*str;

	if (!(str = read_from_file(file_name)))
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	if (!get_points(str, win))
	{
		ft_putendl_fd("error", 2);
		free(str);
		return (0);
	}
	free(str);
	init_bounding_box(win);
	return (1);
}

void		start(char *file_name)
{
	t_mlx	win;

	if (!init_points(&win, file_name))
		return ;
	win.mlx = mlx_init();
	win.size_x = WIN_X;
	win.size_y = WIN_Y;
	win.win = mlx_new_window(win.mlx, win.size_x, win.size_y, "Hello!");
	mlx_hook(win.win, KeyPress, KeyPressMask, &key_hook, &win);
	mlx_hook(win.win, ButtonPress, ButtonPressMask, &mouse_press, &win);
	mlx_hook(win.win, MotionNotify, Button1MotionMask, &mouse_btn1_move, &win);
	mlx_hook(win.win, DestroyNotify, 0, &finish, &win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_y, win.img.size_x);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	win.real = 0;
	reset_view(&win);
	draw(&win);
	mlx_loop(win.mlx);
}
