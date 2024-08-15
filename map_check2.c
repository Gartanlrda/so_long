/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:36:25 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 05:36:10 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_border(t_win *mlx)
{
	char	**map;
	t_coord	c;

	c.y = -1;
	map = copy_tab(mlx->map);
	while (++c.y < mlx->y)
	{
		c.x = -1;
		while (map[c.y][++c.x])
		{
			if ((c.x == 0 || c.x == mlx->x - 1 || c.y == 0 \
				|| c.y == mlx->y - 1) && map[c.y][c.x] != '1')
			{
				free_tab(map, mlx->y);
				return (0);
			}
		}
	}
	free_tab(map, mlx->y);
	return (1);
}

void	check_elements(char c, int *P, int *C, int *E)
{
	if (c == 'P')
		(*P)--;
	else if (c == 'C')
		(*C)--;
	else if (c == 'E')
		(*E)--;
}
