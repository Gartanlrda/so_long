/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:37:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/18 14:57:49 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win		*mlx;

	mlx = NULL;
	if (argc != 2 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		return (ft_printf("Error\nInvalid argument\n"));
	else
	{
		mlx = ft_calloc(1, sizeof(t_win));
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
