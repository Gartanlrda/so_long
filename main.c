/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:37:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/13 11:55:27 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win	mlx;
	void	*img1;
	void	*img2;
	char	*relative_path1 = "./Tileset/grass_floor.xpm";
	char	*relative_path2 = "./Tileset/tree_wall.xpm";
	int		img_width;
	int		img_height;

	if (argc != 2)
		return (0);
	else
	{
		mlx.y = 0;
		mlx.x = 0;
		coord_map(argv[1], &mlx);
		copy_map(argv[1], &mlx);
		flood_fill(&mlx);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, (mlx.x * TILE), (mlx.y * TILE), "Bon deja");
		// printf("%i, %i\n", mlx.y * TILE, mlx.x * TILE);
		img1 = mlx_xpm_file_to_image(mlx.mlx, relative_path1, &img_width, &img_height);
		img2 = mlx_xpm_file_to_image(mlx.mlx, relative_path2, &img_width, &img_height);
		make_map(&mlx, img1, img2);
		mlx_key_hook(mlx.win, key_hook, &mlx);
		mlx_hook(mlx.win, 17, 0L, close_win, &mlx);
		mlx_loop(mlx.mlx);
	}
}

// int	main(void)
// {
// 	t_win	mlx;
// 	void	*img1;
// 	void	*img2;
// 	char	*relative_path1 = "./grass_floor.xpm";
// 	char	*relative_path2 = "./tree_wall.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx.h = 4 * TILE;
// 	mlx.w = 4 * TILE;
// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, mlx.h, mlx.w, "Aller laa");
// 	mlx_key_hook(mlx.win, key_hook, &mlx);
// 	mlx_hook(mlx.win, 17, 0L, close_win, &mlx);
// 	ft_put_pixel(&mlx, 250, 250, 0x00FF0000);
// 	img1 = mlx_xpm_file_to_image(mlx.mlx, relative_path1, &img_width, &img_height);
// 	img2 = mlx_xpm_file_to_image(mlx.mlx, relative_path2, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 0, 0);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 150, 0);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 300, 0);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 450, 0);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 0, 150);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img1, 150, 150);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img1, 300, 150);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 450, 150);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 0, 300);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img1, 150, 300);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img1, 300, 300);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 450, 300);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 0, 450);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 150, 450);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 300, 450);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img2, 450, 450);
// 	mlx_loop(mlx.mlx);
// }
