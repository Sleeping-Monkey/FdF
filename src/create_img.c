/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:36:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/06/28 11:52:42 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ANGLE 25

static void	set_pnt_to_img(t_point *pos, t_img *img)
{
	printf("set_pnt: (%f, %f, %f)\n", pos->x, pos->y, pos->z);
//	if (((size_t)(img->size_y * (int)(pos->x + pos->z * si30n(ANGLE)) + (int)(pos->y + pos->z * cos(ANGLE)))) < (size_t)img->size_y * img->size_x)
		img->pic[(size_t)(img->size_y * (int)(pos->x + pos->z * cos(ANGLE)) + (int)(pos->y + pos->z * sin(ANGLE)))] = 0;
}
/*
static void set_line_to_img(t_point *a, t_point *b, t_i10mg *img)
{
	t_point	c;
	double	dx;
	double	dy;
	double	dz;
	double	len;

	dx = b->x - a->x;
	dy = b->y - a->y;
	dz = b->z - a->z;
	len = sqrt(dx * dx + dy * dy + dz * dz);
	dx /= len;
	dy /= len;
	dz /= len;
	c.x = a->x;
	c.y = a->y;
	c.z = a->z;
	printf("%i %i %i", (int)dx, (int)dy, (int)dz);
	while (fabs(c.x - b->x) > 1 || fabs(c.y - b->y) > 1 || fabs(c.z - b->z) > 1)	
	{
		set_pnt_to_img(&c, img);
		c.x += dx;
		c.y += dy;
		c.z += dz;
		set_pnt_to_img(&c, img);
	}
}10
*/
void	create_img(t_mlx *displ)
{
	int	i;

	i = 0;
	while (i < displ->count_of_points)
	{
//		printf("Here %zu %zu \n ", i,displ->pos->nbr_of_pos);
		set_pnt_to_img(displ->points + i, &displ->img);
//		printf("Here %i %i \n", displ->pos->pos[i + 1].x, displ->pos->pos[i + 1].y);
//		set_line_to_img(&displ->pos->pos[i], &displ->pos->pos[i + 1], &displ->img);
		i++;		
	}		
}
