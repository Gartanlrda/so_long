/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:37:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/09 17:55:09 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extract_map(char *path, t_win *mlx)
{
	int		i;
	int		fd;
	char	*line;
	
	i = 0;
	fd = open(path, O_RDONLY);
	printf("Map open\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (mlx->w == 0)
			mlx->w = (ft_strlen(line) - 1);
		mlx->h++;
		mlx->map = ft_calloc(mlx->w, sizeof(char*));
		mlx->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
	return ;
}

void	make_map(t_win *mlx, void *img1, void *img2)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("width %d\n", mlx->w);
	printf("height %d\n", mlx->h);
	while (x < mlx->w)
	{
		while (y < mlx->h)
		{
			if (x == 0 || y == 0 || y == (mlx->h -1)  || x == (mlx->w -1) )
			{
				printf("%i, %i\n", x, y);
				mlx_put_image_to_window(mlx->mlx, mlx->win, img2, x * TILE, y * TILE);
			}	
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, img1, x * TILE, y * TILE);
			y += 1;
		}
		y = 0;
		x += 1;
	}
	printf("endmap\n");
}

int	main(int argc, char **argv)
{
	t_win	mlx;
	void	*img1;
	void	*img2;
	char	*relative_path1 = "./grass_floor.xpm";
	char	*relative_path2 = "./tree_wall.xpm";
	int		img_width;
	int		img_height;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	else
	{
		mlx.h = 0;
		mlx.w = 0;
		extract_map(argv[1], &mlx);
		while(i < mlx.h)
		{
			printf("%s\n", mlx.map[i]);
			i++;
		}
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, (mlx.w * TILE), (mlx.h * TILE), "Bon deja");
		printf("%i, %i\n", mlx.h * TILE, mlx.w * TILE);
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
