/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 04:52:32 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 05:39:51 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	resize_map(t_win *mlx, char **map, t_coord c)
{
	int	x;
	int	y;

	x = 10;
	y = 5;
	while (c.x > 0 && x >= 0)
	{
		c.x--;
		x--;
	}
	while (c.y > 0 && y >= 0)
	{
		c.y--;
		y--;
	}
	put_map(mlx, map, c);
}

void	put_map(t_win *mlx, char **map, t_coord c)
{
	int	base_x;
	int	x;
	int	y;

	base_x = c.x;
	y = 0;
	while (y <= 10 && c.y < mlx->y)
	{
		c.x = base_x;
		x = 0;
		while (x <= 19 && c.x < mlx->x)
		{
			put_tiles(mlx, map[c.y][c.x], x, y);
			x++;
			c.x++;
		}
		y++;
		c.y++;
	}
}

void	put_tiles(t_win *mlx, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.wall.img, \
			x * TILE, y * TILE);
	else if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.floor.img, \
			x * TILE, y * TILE);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.character.img, \
			x * TILE, y * TILE);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.exit.img, \
			x * TILE, y * TILE);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.collectible.img, \
			x * TILE, y * TILE);
	else if (c == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->lib.char_exit.img, \
			x * TILE, y * TILE);
}
