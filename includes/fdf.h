/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:17 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/09 14:59:13 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "libft.h"
# include "mlx.h"
# include "mat.h"
# include "keys.h"

# define BUFF_SIZE	4096
# define WIN_X 1000
# define WIN_Y 1000
# define USG_MSG	"./fdf file_name\n"

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;
# define COLOR(r, g, b)((t_color){r, g, b})

typedef struct	s_point
{
	t_vec3	c;
	t_color	color;
}				t_point;

typedef	struct	s_img
{
	void	*img;
	int		*pic;
	int		bpp;
	int		size_y;
	int		size_x;
	int		size_line;
	int		endian;
}				t_img;

typedef struct  s_terran
{
	t_vec3 	**points;
	t_mat4  mat;
	t_vec3  pos;
}               t_terran;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	unsigned	size_x;
	unsigned	size_y;
	t_point		*points;
	int			line_of_points;
	int			count_of_points;
	t_point		left;
	t_point		right;
	t_img		img;

	t_mat4		camera_space;
}				t_mlx;

int				get_points(char *altitudes, t_mlx *displ);
int				get_height_and_color(char *str, int *height, int *color);

char			*read_from_file(char *file_name);

void			free_int_arr(int ***arr);
size_t			ft_size_of_arr(char **arr);

void			start(char *file_name);
void			finish(t_mlx *displ);
int				key_hook(int k, t_mlx *win);
int				mouse_hook(int button, int x, int y, t_mlx *win);

void			create_img(t_mlx *win);

void			fill_win(t_mlx *win, t_color *color);
void			draw(t_mlx *win);
void			reset_view(t_mlx *win);
#endif