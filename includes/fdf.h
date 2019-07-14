/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:17 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/13 14:08:22 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <X11/X.h>

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
# define PACK_COLOR(c)((((unsigned)((c.r << 8u) + c.g) << 8u) + c.b))

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

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	unsigned	size_x;
	unsigned	size_y;
	t_point		*points;
	int			line_of_points;
	int			count_of_points;
	t_vec3		left;
	t_vec3		right;
	t_vec3		center;
	t_img		img;
	unsigned	mouse_flag;
	int			mouse_x;
	int			mouse_y;
	unsigned	real;

	t_mat4		camera_space;
}				t_mlx;

void			start(char *file_name);
int				finish(t_mlx *win);
char			*read_from_file(char *file_name);
int				get_points(char *altitudes, t_mlx *win);
void			count_of_points(int **int_arr, int *count, int *line);
int				get_height_and_color(char *str, int *height, int *color);
void			create_img(t_mlx *win);

void			free_int_arr(int ***arr);
size_t			ft_size_of_arr(char **arr);

int				key_hook(int k, t_mlx *win);
int				mouse_press(int button, int x, int y, t_mlx *win);
int				mouse_release(int button, int x, int y, t_mlx *win);
int 			mouse_move(int x, int y, t_mlx *win);

/*
** win.c Window methods
*/
void			fill_win(t_mlx *win, t_color *color);
void			draw(t_mlx *win);
void			reset_view(t_mlx *win);

#endif
