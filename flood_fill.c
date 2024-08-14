/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:17 by gartan            #+#    #+#             */
/*   Updated: 2024/08/14 23:38:23 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_character(char **map, t_coord *c)
{
	while (map[c->y][c->x] != 'P')
	{
		if (map[c->y][c->x] == '\0')
		{
			c->x = 0;
			c->y++;
		}
		c->x++;
	}
	return ;
}

int	get_exit(char **map)
{
	t_coord	c;

	c.x = 0;
	c.y = 0;
	while (map[c.y][c.x] != 'E')
	{
		if (map[c.y][c.x] == '\0' || map[c.y][c.x] == '\n')
		{
			c.x = 0;
			c.y++;
		}
		c.x++;
	}
	if (map[c.y + 1][c.x] == 'X' || map[c.y][c.x - 1] == 'X'\
		|| map[c.y][c.x + 1] == 'X' || map[c.y - 1][c.x] == 'X')
		return (1);
	else
		return (0);
}

void	fill_possible(char **map, t_coord c, t_win *mlx)
{
	map[c.y][c.x] = 'X';
	if (map[c.y - 1][c.x] != 'X' && map[c.y - 1][c.x] != '1' && map[c.y - 1][c.x] != 'E')
	{
		c.y = c.y - 1;
		fill_possible(map, c, mlx);
		c.y = c.y + 1;
	}
	if (map[c.y + 1][c.x] != '1' && map[c.y + 1][c.x] != 'X' && map[c.y + 1][c.x] != 'E')
	{
		c.y = c.y + 1;
		fill_possible(map, c, mlx);
		c.y = c.y - 1;
	}
	if (map[c.y][c.x + 1] != '1' && map[c.y][c.x + 1] != 'X' && map[c.y][c.x + 1] != 'E')
	{
		c.x = c.x + 1;
		fill_possible(map, c, mlx);
		c.x = c.x - 1;
	}
	if (map[c.y][c.x - 1] != '1' && map[c.y][c.x - 1] != 'X' && map[c.y][c.x - 1] != 'E')
	{
		c.x = c.x - 1;
		fill_possible(map, c, mlx);
		c.x = c.x + 1;
	}
}
int	map_doable(char **map, t_win mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx.y)
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			else
				x++;
		}
		x = 0;
		y++;
	}
	if (get_exit(map) == 0)
		return (0);
	return (1);
}

int	flood_fill(t_win *mlx)
{
	char	**map;
	t_coord	c;

	c.x = 0;
	c.y = 0;
	map = copy_tab(mlx->map);
	get_character(map, &c);
	fill_possible(map, c, mlx);
	if (map_doable(map, *mlx) == 0)
	{
		free_tab(map, mlx->y);
		return (0);
	}
	else
	{
		free_tab(map, mlx->y);
		return (1);
	}
}
