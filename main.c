/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:53 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/30 17:00:22 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	printf("color: %i\n", (t << 24 | r << 16 | g << 8 | b));
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_fullscreen(t_vars vars)
{
	int	x;
	int	y;
	int	i;

	x = 1;
	i = 255;
	while (x < vars.lon)
	{
		y = 1;
		while (y < vars.lar)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, create_trgb(((x / 256)+(x / 256)),(x / 256),(y / 256), i));
			y++;
		}
		x++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
//	printf("keybind: %i\n", keycode);
	if (keycode == 65307)
		close(vars);
	else if (keycode == 97)
		incrust(*vars, 0, 0);
	else if (keycode == 114)
		vars->color = 0xFFFF0000;
	else if (keycode == 103)
		vars->color = 0xFF00FF00;
	else if (keycode == 98)
		vars->color = create_trgb(255,10,10,255);
	else if (keycode == 115)
		//printf("color: %i\n", create_trgb(10,10,10,10));
		ft_fullscreen(*vars);
	else
		printf("keybind: %i\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
//	y = y;
//	x = x;
//	keycode = keycode;
	if (keycode == 1)
		incrust(*vars, x, y);
	printf("mouse bind: %d\n mouse pos x: %i  y: %i\n", keycode, x, y);
	return (0);
}

void	incrust(t_vars vars, int x, int y)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			mlx_pixel_put(vars.mlx, vars.win, i + x, j + y, vars.color);
			j++;
		}
		i++;
	}
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.lon = 1820;
	vars.lar = 500;
	vars.color = 0x00FF9999;
	vars.mlx = mlx_init();
	vars.img.img = mlx_new_image(vars.mlx, vars.lon, vars.lar);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.win = mlx_new_window(vars.mlx, vars.lon, vars.lar, "Hello world!");
	my_mlx_pixel_put(&vars.img, 1, 1, 0x00FF9999);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 10, 10);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_loop(vars.mlx);
}
