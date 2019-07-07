/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:36:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/07 15:15:54 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ANGLE 25

static void	set_pnt_to_img(t_point *pos, t_img *img)
{
	printf("set_pnt: (%f, %f, %f)\n", pos->c.x, pos->c.y, pos->c.z);
	if (pos->c.x + pos->c.z * cos(ANGLE) < img->size_x && pos->c.y + \
	pos->c.z * sin(ANGLE) < img->size_y)
		img->pic[(size_t)(img->size_y * (int)(pos->c.x + pos->c.z * \
		cos(ANGLE)) + (int)(pos->c.y + pos->c.z * sin(ANGLE)))] = 0;
}

static void	set_line_to_img(t_point *a, t_point *b, t_img *img)
{
	t_point	c;
	double	dx;
	double	dy;
	double	dz;
	double	len;

	dx = b->c.x - a->c.x;
	dy = b->c.y - a->c.y;
	dz = b->c.z - a->c.z;
	len = sqrt(dx * dx + dy * dy + dz * dz);
	dx /= len;
	dy /= len;
	dz /= len;
	c.c.x = a->c.x;
	c.c.y = a->c.y;
	c.c.z = a->c.z;
	printf("%i %i %i", (int)dx, (int)dy, (int)dz);
	while (fabs(c.c.x - b->c.x) > 1 || fabs(c.c.y - b->c.y) > 1 || \
	fabs(c.c.z - b->c.z) > 1)
	{
		set_pnt_to_img(&c, img);
		c.c.x += dx;
		c.c.y += dy;
		c.c.z += dz;
		set_pnt_to_img(&c, img);
	}
}

void		create_img(t_mlx *displ)
{
	int	i;

	i = 0;
	while (i < displ->count_of_points - 1)
	{
		if (i + 1 % displ->line_of_points != 0)
			set_line_to_img(&displ->points[i], &displ->points[i + 1], \
			&displ->img);
		if (i + displ->line_of_points < displ->count_of_points)
			set_line_to_img(&displ->points[i], \
			&displ->points[i + displ->line_of_points], &displ->img);
		i++;
	}
}
