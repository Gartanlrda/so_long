/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:53 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/28 18:18:29 by ggoy             ###   ########.fr       */
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
	else
		printf("keybind: %i\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars, t_data *img)
{
//	y = y;
//	x = x;
//	keycode = keycode;
	vars = NULL;
	if (keycode == 1)
		incrust(x, y, *img);
	printf("mouse bind: %d\n mouse pos x: %i  y: %i\n", keycode, x, y);
	return (0);
}

void	incrust(int x, int y,t_data img)
{
	int	i;
	
	i = 20;
	while (y <= (y + i))
	{
		while (x <= (x + i))
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		x = x - i;
		y++;
	}
}

int	render_next_frame(void *YourStruct)
{
	YourStruct = NULL;

	return (0);
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
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_loop(vars.mlx);
}
