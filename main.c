/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:53 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/06 17:09:33 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "libft/libft.h"

// int	create_trgb(int t, int r, int g, int b)
// {
// 	// printf("color: %i\n t: %i\n r: %i\n g: %i\n b: %i\n", (t << 24 | r << 16 | g << 8 | b), t, r, g, b);
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int	get_r(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int	get_g(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	ft_fullscreen(t_win win)
// {
// 	float	x;
// 	float	y;
// 	float	i;

// 	win.img1.img = mlx_new_image(win.mlx, win.lon, win.lar);
// 	win.img1.addr = mlx_get_data_addr(win.img1.img, &win.img1.bits_per_pixel, &win.img1.line_length, &win.img1.endian);
// 	x = 0;
// 	i = 254;
// 	while (x < win.lon)
// 	{
// 		y = 0;
// 		while (y < win.lar)
// 		{
// 			win.color = create_trgb(i,(int)((x / win.lon) * 255),(int)((y/win.lar) * 255), 255/2);
// 			my_mlx_pixel_put(&win.img1, x, y, win.color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(win.mlx, win.win, win.img1.img, 0, 0);
// }

// int	key_hook(int keycode, t_win *win)
// {
// 	if (keycode == 65307)
// 		close(win);
// 	else if (keycode == 97)
// 		incrust(*win, 0, 0);
// 	else if (keycode == 114)
// 		win->color = 0xFFFF0000;
// 	else if (keycode == 103)
// 		win->color = 0xFF00FF00;
// 	else if (keycode == 98)
// 		win->color = create_trgb(255,10,10,255);
// 	else if (keycode == 115)
// 		ft_fullscreen(*win);
// 	else if (keycode == 112)
// 		incrust(*win, (win->lon/2), (win->lar/2));
// 	else
// 		printf("keybind: %i\n", keycode);
// 	return (0);
// }

// int	mouse_hook(int keycode, int x, int y, t_win *win)
// {
// 	if (keycode == 1)
// 		incrust(*win, x, y);
// 	printf("mouse bind: %d\n mouse pos x: %i  y: %i\n", keycode, x, y);
// 	return (0);
// }

// void	incrust(t_win win, int x, int y)
// {
// 	int		i;
// 	int		j;
	
// 	i = 0;
// 	win.img1.img = mlx_new_image(win.mlx, 25, 25);
// 	win.img1.addr = mlx_get_data_addr(win.img1.img, &win.img1.bits_per_pixel, &win.img1.line_length, &win.img1.endian);
// 	while (i < 25)
// 	{
// 		j = 0;
// 		while (j < 25)
// 		{
// 			my_mlx_pixel_put(&win.img1, i, j, win.color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(win.mlx, win.win, win.img1.img, x, y);
// }

// int	close(t_win *win)
// {
// 	mlx_destroy_window(win->mlx, win->win);
// 	exit (EXIT_SUCCESS);
// 	return (0);
// }

// void	ft_cpy_background(t_data img1, t_data img2, t_win win)
// {
// 	int	x;
// 	int	y;
	
// 	x = 0;
// 	while (x <= win.lon)
// 	{
// 		y = 0;
// 		while (y <= win.lar)
// 		{
// 			printf("bsr\n");
// 			my_mlx_pixel_put(&img2, x, y, *(unsigned int*)(img1.addr));
// 			printf("bjr\n");
// 			y++;
// 		}
// 		x++;
// 	}
// }

// int	render_next_frame(t_win win)
// {
// 	static int	frame = 1;

// 	if (frame == 1)
// 	{
// 		ft_cpy_background(win.img1, win.img2, win);
// 		mlx_put_image_to_window(win.mlx, win.win, win.img2.img, 0, 0);
// 		frame++;
// 	}
// 	else if (frame == 2)
// 	{
// 		ft_cpy_background(win.img2, win.img1, win);
// 		mlx_put_image_to_window(win.mlx, win.win, win.img1.img, 0, 0);
// 		frame--;
// 	}
// 	return (1);
// }


// int	main(void)
// {
// 	t_win	win;

// 	win.lon = 910;
// 	win.lar = 490;
// 	win.color = 0x00FF9999;
// 	win.mlx = mlx_init();	
// 	win.img2.img = mlx_new_image(win.mlx, win.lon, win.lar);
// 	win.img2.addr = mlx_get_data_addr(win.img2.img, &win.img2.bits_per_pixel, &win.img2.line_length, &win.img2.endian);
// 	win.img1.img = mlx_new_image(win.mlx, win.lon, win.lar);
// 	win.img1.addr = mlx_get_data_addr(win.img1.img, &win.img1.bits_per_pixel, &win.img1.line_length, &win.img1.endian);
// 	win.win = mlx_new_window(win.mlx, win.lon, win.lar, "Hello world!");
// 	ft_fullscreen(win);
// 	mlx_key_hook(win.win, key_hook, &win);
// 	mlx_mouse_hook(win.win, mouse_hook, &win);
// 	mlx_hook(win.win, 17, 0L, close, &win);
// 	mlx_loop_hook(win.mlx, render_next_frame, &win);
// 	mlx_loop(win.mlx);
// }

int main(void) {
 	t_win tutorial;
	t_img image;
	t_animator animator3000;

	tutorial = new_window(300, 300, "animations");
	if (!tutorial.win_ptr)
		return (2);
 	image = new_img(300, 300, tutorial);
	animator3000 = (t_animator){NULL, &tutorial, &image};
//	ft_lstadd_back(&animator3000.animations, ft_lstnew(ball_animation(5, 32)));
//	ft_lstadd_back(&animator3000.animations, ft_lstnew(rect_animation(5, 32)));
//	ft_lstadd_back(&animator3000.animations, ft_lstnew(orbit(5, 32)));
	ft_lstadd_back(&animator3000.animations, ft_lstnew(semaphore(5, 32)));
	mlx_loop_hook(tutorial.mlx_ptr, update, &animator3000);
	mlx_loop(tutorial.mlx_ptr);
	destroy_image(image);
	destroy_window(tutorial);
	return (0);
}