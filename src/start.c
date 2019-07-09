/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:47:14 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 14:54:16 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bounding_box(t_mlx *displ)
{
	int	i;

	i = 0;
	displ->left.c = VEC(displ->points[0].c.x, displ->points[0].c.y, \
	displ->points[0].c.z);
	displ->right.c = VEC(displ->points[0].c.x, displ->points[0].c.y, \
	displ->points[0].c.z);
	while (++i < displ->count_of_points)
	{
		if (displ->left.c.x > displ->points[i].c.x)
			displ->left.c.x = displ->points[i].c.x;
		if (displ->left.c.y > displ->points[i].c.y)
			displ->left.c.y = displ->points[i].c.y;
		if (displ->left.c.z > displ->points[i].c.z)
			displ->left.c.z = displ->points[i].c.z;
		if (displ->right.c.x < displ->points[i].c.x)
			displ->right.c.x = displ->points[i].c.x;
		if (displ->right.c.y < displ->points[i].c.y)
			displ->right.c.y = displ->points[i].c.y;
		if (displ->right.c.z < displ->points[i].c.z)
			displ->right.c.z = displ->points[i].c.z;
	}
}

int		init_points(t_mlx *displ, char *file_name)
{
	char	*str;

	if (!(str = read_from_file(file_name)))
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	if (!get_points(str, displ))
	{
		ft_putendl_fd("error", 2);
		free(str);
		return (0);
	}
	free(str);
	init_bounding_box(displ);
	return (1);
}

void	start(char *file_name)
{
	t_mlx	win;

	if (!init_points(&win, file_name))
		return ;
	win.mlx = mlx_init();
	win.size_x = WIN_X;
	win.size_y = WIN_Y;
	win.win = mlx_new_window(win.mlx, win.size_x, win.size_y, "Hello!");
	mlx_key_hook(win.win, &key_hook, &win);
	mlx_mouse_hook(win.win, &mouse_hook, &win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_y, win.img.size_x);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	reset_view(&win);
	draw(&win);
	mlx_loop(win.mlx);
}
