/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:05 by gartan            #+#    #+#             */
/*   Updated: 2024/08/07 12:27:33 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	close_win(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit (EXIT_SUCCESS);
	return (0);
}

void	ft_put_pixel(t_win *win, int x, int y, int color)
{
	t_img	img;

	img.img = mlx_new_image(win->mlx, win->w, win->h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, x, y, color);
	mlx_put_image_to_window(win->mlx, win->win, img.img, 0, 0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_fullscreen(t_win win)
{
	t_img	img;
	float	x;
	float	y;
	float	i;

	img.img = mlx_new_image(win.mlx, win.h, win.w);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	x = 0;
	i = 254;
	while (x < win.w)
	{
		y = 0;
		while (y < win.h)
		{
			win.color = create_trgb(i,(int)((x / win.h) * 255),(int)((y/win.w) * 255), 255/2);
			my_mlx_pixel_put(&img, x, y, win.color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
