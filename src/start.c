/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:47:14 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/14 16:38:43 by bnesoi           ###   ########.fr       */
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
	mlx_hook(win.win, 2, 0, &key_hook, &win);
	mlx_hook(win.win, 4, 0, &mouse_press, &win);
	mlx_hook(win.win, 5, 0, &mouse_release, &win);
	mlx_hook(win.win, 6, 0, &mouse_move, &win);
	mlx_hook(win.win, 17, 0, &finish, &win);
	mlx_do_key_autorepeaton(win.win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_y, win.img.size_x);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	win.real = 0;
	reset_view(&win, &VEC(0, 45, 45));
	draw(&win);
	mlx_loop(win.mlx);
}
