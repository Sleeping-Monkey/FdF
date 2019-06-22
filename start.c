/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:47:14 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/22 13:53:15 by ssheba           ###   ########.fr       */
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
	if (!(all->points = get_points(str, &all->count_of_points)))
	{
		ft_putendl_fd("error", 2);
		return (0);
	}
	free(str);
    return (1);
}

void    start(char *file_name)
{
    t_mlx   displ;
	int		i;

    if (!init_points(&displ, file_name))
        return ;
    displ.mlx = mlx_init();
    displ.size_x = 2000;
	displ.size_y = 2000;
	displ.win = mlx_new_window(displ.mlx, displ.size_x, displ.size_y, "Hello!");
    mlx_key_hook(displ.win, &key_hook, &displ);
	mlx_mouse_hook(displ.win, &mouse_hook, &displ);
	displ.img.size_x = displ.size_x;
	displ.img.size_y = displ.size_y;
	displ.img.img = mlx_new_image(displ.mlx, displ.img.size_y, displ.img.size_x);
	displ.img.pic = (int *)mlx_get_data_addr(displ.img.img,
						&displ.img.bpp, &displ.img.size_line, &displ.img.endian);
	i = 0;
	while (i < displ.img.size_x * displ.img.size_y)
		displ.img.pic[i++] = (((255 << 8) + 255) << 8) + 255;
	mlx_put_image_to_window(displ.mlx, displ.win, displ.img.img, 0, 0);	
	create_img(&displ);
    mlx_loop(displ.mlx);
}