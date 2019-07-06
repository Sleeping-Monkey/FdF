/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:13:17 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/06 14:26:53 by bnesoi           ###   ########.fr       */
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

# define BUFF_SIZE	4096
# define USG_MSG	"./fdf file_name\n"

typedef struct	s_point
{
	t_vec3 c;
	t_vec3  color;
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
	t_img		img;

	t_mat4		camera_space;
}				t_mlx;

t_point			*get_points(char *altitudes, int *count, int *line_size);

char			*read_from_file(char *file_name);

void			free_int_arr(int ***arr);
size_t			ft_size_of_arr(char **arr);

void			start(char *file_name);
int				key_hook(int keycode, t_mlx *displ);
int				mouse_hook(int button, int x, int y, t_mlx *displ);

void			create_img(t_mlx *displ);

void            draw(t_terran *terran, t_mlx *displ);

#endif