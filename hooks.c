/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:27:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/18 14:57:25 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		mlx_loop_end(win->mlx);
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
	if (win->map[c.y - 1][c.x] == '0' && win->map[c.y][c.x] != 'X')
	{
		move(win, c, 'U', 'P');
		ft_printf("move: %i\n", win->moves++);
	}
	else if (win->map[c.y - 1][c.x] == 'C')
	{
		move(win, c, 'U', 'P');
		ft_printf("move: %i\n", win->moves++);
		win->collectibles--;
	}
	else if (win->map[c.y - 1][c.x] == 'E' && win->collectibles == 0)
	{
		move(win, c, 'U', 'X');
		ft_printf("move: %i\n", win->moves++);
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
	if (win->map[c.y][c.x - 1] == '0' && win->map[c.y][c.x] != 'X')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'L', 'P');
	}
	else if (win->map[c.y][c.x - 1] == 'C')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'L', 'P');
		win->collectibles--;
	}
	else if (win->map[c.y][c.x - 1] == 'E' && win->collectibles == 0)
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'L', 'X');
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
	if (win->map[c.y][c.x + 1] == '0' && win->map[c.y][c.x] != 'X')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'R', 'P');
	}
	else if (win->map[c.y][c.x + 1] == 'C')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'R', 'P');
		win->collectibles--;
	}
	else if (win->map[c.y][c.x + 1] == 'E' && win->collectibles == 0)
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'R', 'X');
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
	if (win->map[c.y + 1][c.x] == '0' && win->map[c.y][c.x] != 'X')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'D', 'P');
	}
	else if (win->map[c.y + 1][c.x] == 'C')
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'D', 'P');
		win->collectibles--;
	}
	else if (win->map[c.y + 1][c.x] == 'E' && win->collectibles == 0)
	{
		ft_printf("move: %i\n", win->moves++);
		move(win, c, 'D', 'X');
	}
}
