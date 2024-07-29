/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:53 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/29 15:31:20 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
//	printf("keybind: %i\n", keycode);
	if (keycode == 65307)
		close(vars);
	if (keycode == 97)
		incrust(*vars, 0, 0);
	else
		printf("keybind: %i\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
//	y = y;
//	x = x;
//	keycode = keycode;
	vars->h = x;
	if (keycode == 1)
		incrust(*vars, x, y);
	printf("mouse bind: %d\n mouse pos x: %i  y: %i\n", keycode, x, y);
	return (0);
}

void	incrust(t_vars vars, int x, int y)
{
	int		i;
	int		j;
	t_data	img;
	
	i = 0;
	img.img = mlx_new_image(vars.mlx, 5, 5);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			mlx_pixel_put(vars.mlx, vars.win, i + x, j + y, 0x00FFFFFF);
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
	t_data	img;

	vars.h = 500;
	vars.l = 1820;
	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, vars.h, vars.l);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.win = mlx_new_window(vars.mlx, vars.l, vars.h, "Hello world!");
	my_mlx_pixel_put(&img, 0, 0, 0x00FF9999);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_loop(vars.mlx);
}
