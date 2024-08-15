/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:02 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 05:25:04 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup_sl(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i])
		i++;
	result = (char *) malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	if (result[i - 1] == '\n')
		result[i - 1] = '\0';
	return (result);
}

char	**copy_tab(char **map)
{
	char	**tab;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tab = ft_calloc(i, sizeof(char *));
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strdup(map[i]);
		i++;
	}
	return (tab);
}

void	final_touch(t_win *mlx)
{
	char	**map;
	t_coord	c;

	c.x = 0;
	c.y = 0;
	map = copy_tab(mlx->map);
	get_character(map, &c);
	if (mlx->collectibles == 0 && map[c.y][c.x] == 'X')
	{
		ft_printf("SUCCESS!\n Final count: %i\n", mlx->moves - 1);
	}
	free_tab(map, mlx->y);
}

void	move(t_win *win, t_coord c, char n, char x)
{
	win->map[c.y][c.x] = '0';
	if (n == 'U')
		win->map[c.y - 1][c.x] = x;
	else if (n == 'L')
		win->map[c.y][c.x - 1] = x;
	else if (n == 'R')
		win->map[c.y][c.x + 1] = x;
	else if (n == 'D')
		win->map[c.y + 1][c.x] = x;
}

int	charcmp(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		else
			i++;
	}
	return (1);
}
