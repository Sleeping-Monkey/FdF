#include <fdf.h>

void			fill_win(t_mlx *win, t_color *color)
{
	size_t i;

	i = 0;
	while (i < win->img.size_x * win->img.size_y)
		win->img.pic[i++] = (int)((unsigned)((color->r << 8u) + color->g) << 8u) + color->b;
}

void			draw(t_mlx *win)
{
	fill_win(win, &COLOR(255, 255, 255));
	create_img(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}

void			reset_view(t_mlx *win)
{
	m4_identity(&win->camera_space);
	m4_rotate(&win->camera_space, &VEC(0, 45, 45));
	m4_translate(&win->camera_space, &VEC(-60, -100, 0));
}