/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:47:14 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/28 11:54:21 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     init_points(t_mlx *all, char *file_name)
{
    char    *str;

    if (!(str = read_from_file(file_name)))
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	if (!(all->points = get_points(str, &all->count_of_points, &all->line_of_points)))
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	free(str);
    return (1);
}

void    start(char *file_name)
{
    t_mlx   win;
	int		i;

    if (!init_points(&win, file_name))
        return ;
//	printf("%i %i =(\n", win.count_of_points, win.line_of_points);
    win.mlx = mlx_init();
    win.size_x = 300;
	win.size_y = 300;
	win.win = mlx_new_window(win.mlx, win.size_x, win.size_y, "Hello!");
    mlx_key_hook(win.win, &key_hook, &win);
	mlx_mouse_hook(win.win, &mouse_hook, &win);
	win.img.size_x = win.size_x;
	win.img.size_y = win.size_y;
	win.img.img = mlx_new_image(win.mlx, win.img.size_y, win.img.size_x);
	win.img.pic = (int *)mlx_get_data_addr(win.img.img,
						&win.img.bpp, &win.img.size_line, &win.img.endian);
	i = 0;
	while (i < win.img.size_x * win.img.size_y)
		win.img.pic[i++] = (((255 << 8) + 255) << 8) + 255;
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	create_img(&win);
    mlx_loop(win.mlx);
}