/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:27:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/14 23:45:03 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		close_win(win);
	else if (keycode == UP || keycode == Z || keycode == W)
	{
		move_up(win);
		make_map(win);
	}
	else if (keycode == LEFT || keycode == Q || keycode == A)
	{
		move_left(win);
		make_map(win);
	}
	else if (keycode == DOWN || keycode == S)
	{
		move_down(win);
		make_map(win);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		move_right(win);
		make_map(win);
	}
	else
		ft_printf("keybind: %i\n", keycode);
	return (0);
}

void	move_up(t_win *win)
{
	t_coord	c;
	char	**map;

	c.x = 0;
	c.y = 0;
	map = copy_tab(win->map);
	get_character(map, &c);
	free_tab(map, win->y);
	if (win->map[c.y - 1][c.x] == '0')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y - 1][c.x] = 'P';
	}
	else if (win->map[c.y - 1][c.x] == 'C')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y - 1][c.x] = 'P';
		win->collectibles--;
	}
	else if (win->map[c.y - 1][c.x] == 'E' && win->collectibles == 0)
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y - 1][c.x] = 'X';
	}
}

void	move_left(t_win *win)
{
	t_coord	c;
	char	**map;

	c.x = 0;
	c.y = 0;
	map = copy_tab(win->map);
	get_character(map, &c);
	free_tab(map, win->y);
	if (win->map[c.y][c.x - 1] == '0')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x - 1] = 'P';
	}
	else if (win->map[c.y][c.x - 1] == 'C')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x - 1] = 'P';
		win->collectibles--;
	}
	else if (win->map[c.y][c.x - 1] == 'E' && win->collectibles == 0)
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x - 1] = 'X';
	}
}

void	move_right(t_win *win)
{
	t_coord	c;
	char	**map;

	c.x = 0;
	c.y = 0;
	map = copy_tab(win->map);
	get_character(map, &c);
	free_tab(map, win->y);
	if (win->map[c.y][c.x + 1] == '0')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x + 1] = 'P';
	}
	else if (win->map[c.y][c.x + 1] == 'C')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x + 1] = 'P';
		win->collectibles--;
	}
	else if (win->map[c.y][c.x + 1] == 'E' && win->collectibles == 0)
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y][c.x + 1] = 'X';
	}
}

void	move_down(t_win *win)
{
	t_coord	c;
	char	**map;

	c.x = 0;
	c.y = 0;
	map = copy_tab(win->map);
	get_character(map, &c);
	free_tab(map, win->y);
	if (win->map[c.y + 1][c.x] == '0')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y + 1][c.x] = 'P';
	}
	else if (win->map[c.y + 1][c.x] == '0')
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y + 1][c.x] = 'P';
		win->collectibles--;
	}
	else if (win->map[c.y + 1][c.x] == 'E' && win->collectibles == 0)
	{
		win->map[c.y][c.x] = '0';
		win->map[c.y + 1][c.x] = 'X';
	}
}
