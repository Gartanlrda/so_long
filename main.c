/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:37:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/16 15:42:36 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win		*mlx;

	mlx = ft_calloc(1, sizeof(t_win));
	if (argc != 2)
		return (0);
	else
	{
		mlx->y = 0;
		mlx->x = 0;
		mlx->moves = 1;
		coord_map(argv[1], mlx);
		copy_map(argv[1], mlx);
		if (global_map_check(mlx) == 0)
			make_fail(mlx);
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, (mlx->x * TILE), \
			(mlx->y * TILE), "So_long");
		mlx_key_hook(mlx->win, key_hook, mlx);
		make_imglib(mlx);
		make_map(mlx);
		mlx_hook(mlx->win, 17, 0L, mlx_loop_end, mlx->mlx);
		mlx_loop(mlx->mlx);
		close_win(mlx);
	}
}
