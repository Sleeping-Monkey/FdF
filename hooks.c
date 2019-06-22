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

int		key_hook(int keycode, t_mlx *displ)
{
	if (!displ)
		return (1);
	if (keycode == 53)
		exit(0);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_mlx *displ)
{
	if (!displ)
		return (1);
	if (button == 1)
		mlx_put_image_to_window(displ->mlx, displ->win, displ->img.img, 0, 0);
	printf("(%i, %i) - %i\n", x, y, button);
	return (1);
}

