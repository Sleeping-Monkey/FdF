/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:29:22 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 14:54:39 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	finish(t_mlx *displ)
{
	free(displ->points);
	mlx_destroy_image(displ->mlx, displ->img.img);
	mlx_destroy_window(displ->mlx, displ->win);
	free(displ->mlx);
	exit(0);
}
