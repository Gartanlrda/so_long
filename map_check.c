/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:03:49 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 06:14:49 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	map_dimension(t_win *mlx)
{
	int		y;
	char	**map;

	map = copy_tab(mlx->map);
	y = 0;
	while (y < mlx->y)
	{
		if (ft_strlens(map[y]) != mlx->x)
		{
			free_tab(map, mlx->y);
			return (0);
		}
		else
			y++;
	}
	free_tab(map, mlx->y);
	return (1);
}

int	map_valid_char(t_win *mlx)
{
	char	**map;
	int		y;

	map = copy_tab(mlx->map);
	y = 0;
	while (y < mlx->y)
	{
		if (ft_strcheckstr(map[y], "01PCE") == 0)
		{
			free_tab(map, mlx->y);
			return (0);
		}
		else
			y++;
	}
	free_tab(map, mlx->y);
	return (1);
}

int	map_missing_element(t_win *mlx)
{
	char	**map;
	int		p;
	int		g;
	int		e;
	t_coord	c;

	p = 1;
	g = 1;
	e = 1;
	c.y = -1;
	map = copy_tab(mlx->map);
	while (++c.y < mlx->y)
	{
		c.x = -1;
		while (map[c.y][++c.x])
			check_elements(map[c.y][c.x], &p, &g, &e);
	}
	free_tab(map, mlx->y);
	if (p != 0 || e != 0 || g > 0)
		return (0);
	return (1);
}

void	count_collectibles(t_win *mlx)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = copy_tab(mlx->map);
	mlx->collectibles = 0;
	while (y < mlx->y)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx->collectibles++;
			x++;
		}
		y++;
	}
	free_tab(map, mlx->y);
}

int	global_map_check(t_win *mlx)
{
	if (mlx->x < 3 || mlx->y < 3 || map_dimension(mlx) == 0)
	{
		ft_printf("Wrong map dimension\n");
		return (0);
	}
	if (map_valid_char(mlx) == 0 || map_missing_element(mlx) == 0)
	{
		ft_printf("Character invalid or missing in map parsing\n");
		return (0);
	}
	if (check_border(mlx) == 0)
	{
		ft_printf("Wrong border\n");
		return (0);
	}
	if (flood_fill(mlx) == 0)
	{
		ft_printf("Map road impossible\n");
		return (0);
	}
	else
	{
		count_collectibles(mlx);
		return (1);
	}
}
