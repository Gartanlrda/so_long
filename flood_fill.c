/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:17 by gartan            #+#    #+#             */
/*   Updated: 2024/08/12 18:24:01 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**copy_tab(char **map)
{
	char	**tab;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tab = ft_calloc(i, sizeof(char*));
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strdup(map[i]);
		i++;
	}
	return (tab);
}

void	get_character(char **map, t_coord *c)
{
	while (map[c->y][c->x] != 'P')
	{
		if (c->x == '\0')
		{
			c->x = 0;
			c->y++;
		}
		c->x++;
	}
	return ;
}

void	fill_possible(char **map, t_coord c, t_win *mlx)
{
	map[c.y][c.x] = 'X';
	if (c.y > 0 && (map[c.y - 1][c.x] == '0' || map[c.y - 1][c.x] == 'C'\
		|| map[c.y - 1][c.x] == 'E' || map[c.y - 1][c.x] == 'X'))
	{
		c.y = c.y - 1;
		fill_possible(map, c, mlx);
	}
	if ((c.y < mlx->y - 1) && (map[c.y + 1][c.x] == '0'\
		|| map[c.y + 1][c.x] == 'C' || map[c.y + 1][c.x] == 'E'|| map[c.y + 1][c.x] == 'X'))
	{
		c.y = c.y + 1;
		fill_possible(map, c, mlx);
	}
	if ((c.x < mlx->x - 1) && (map[c.y][c.x + 1] == '0'\
		|| map[c.y][c.x + 1] == 'C' || map[c.y][c.x + 1] == 'E' || map[c.y][c.x + 1] == 'X'))
	{
		c.x = c.x + 1;
		fill_possible(map, c, mlx);
	}
	if (c.x > 0 && (map[c.y][c.x - 1] == '0' || map[c.y][c.x - 1] == 'C'\
		|| map[c.y][c.x - 1] == 'E' || map[c.y][c.x - 1] == 'X'))
	{
		c.x = c.x - 1;
		fill_possible(map, c, mlx);
	}
}
int	map_checker(char **map, t_win mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx.y)
	{
		while (map[y][x])
		{
			printf("x = %i, y = %i\n", x, y);
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (0);
			else
				x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	flood_fill(t_win *mlx)
{
	char	**map;
	int		i;
	t_coord	c;

	c.x = 0;
	c.y = 0;
	map = copy_tab(mlx->map);
	get_character(map, &c);
	fill_possible(map, c, mlx);
	if (map_checker(map, *mlx) == 0)
	{
		printf("map KO\n");
		//exit (EXIT_FAILURE);
	}
	else
		printf("map OK\n");
	i = 0;
	while (i < 5)
	{
		printf("%s\n", map[i]);
		i++;
	}
}
