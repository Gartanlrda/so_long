/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:37:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 05:44:32 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win		*mlx;

	mlx = malloc(sizeof(t_win));
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
			exit (EXIT_FAILURE);
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, (mlx->x * TILE), \
			(mlx->y * TILE), "So_long");
		mlx_key_hook(mlx->win, key_hook, mlx);
		make_imglib(mlx);
		make_map(mlx);
		mlx_hook(mlx->win, 17, 0L, close_win, mlx);
		mlx_loop(mlx->mlx);
	}
	free(mlx);
}
