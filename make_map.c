/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:32:48 by gartan            #+#    #+#             */
/*   Updated: 2024/08/13 18:12:53 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	copy_map(char *path, t_win *mlx)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	mlx->map = ft_calloc(mlx->y + 1, sizeof(char*));
	while (i < mlx->y)
	{
		line = get_next_line(fd);
		mlx->map[i] = ft_strdup_SL(line);
		i++;
		free(line);
	}
	close(fd);
	return ;
}

void	make_imglib(t_imglib *imglib, t_win *mlx)
{
	char	*wall = "./Tileset/grass_floor.xpm";
	char	*floor = "./Tileset/tree_wall.xpm";
	char	*collectible = "./Tileset/collectible.xpm";
	int		img_width;
	int		img_height;

	make_imglib2(imglib, mlx);
	imglib->floor = mlx_xpm_file_to_image(mlx->mlx, floor, &img_width, &img_height);
	imglib->wall = mlx_xpm_file_to_image(mlx->mlx, wall, &img_width, &img_height);
	imglib->collectible = mlx_xpm_file_to_image(mlx->mlx, collectible, &img_width, &img_height);
}

void	make_imglib2(t_imglib *imglib, t_win *mlx)
{
	char	*character = "./Tileset/character.xpm";
	char	*exit = "./Tileset/exit.xpm";
	char	*char_exit = "./Tileset/char_exit.xpm";
	int		img_width;
	int		img_height;

	imglib->character = mlx_xpm_file_to_image(mlx->mlx, character, &img_width, &img_height);
	imglib->exit = mlx_xpm_file_to_image(mlx->mlx, exit, &img_width, &img_height);
	imglib->char_exit = mlx_xpm_file_to_image(mlx->mlx, char_exit, &img_width, &img_height);
}

void	make_map(t_win *mlx, t_imglib *imglib)
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
			if (map[c.y][c.x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, imglib->wall->img, c.x * TILE, c.y * TILE);
			else if (map[c.y][c.x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win,imglib->floor->img, c.x * TILE, c.y * TILE);
			else if (map[c.y][c.x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win,imglib->character->img, c.x * TILE, c.y * TILE);
			else if (map[c.y][c.x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win,imglib->exit->img, c.x * TILE, c.y * TILE);
			else if (map[c.y][c.x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,imglib->collectible->img, c.x * TILE, c.y * TILE);
		}
	}
}

void	*find_img(char c, t_imglib imglib)
{
	if (c == '1')
		return (imglib.wall->img);
	else if (c == '0')
		return (imglib.floor->img);
	else if (c == 'P')
		return (imglib.character->img);
	else if (c == 'E')
		return (imglib.exit->img);
	else
		return (imglib.collectible->img);
}

// void	make_map(t_win *mlx, void *img1, void *img2)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;

// 	while (x < mlx->x)
// 	{
// 		while (y < mlx->y)
// 		{
// 			if (x == 0 || y == 0 || y == (mlx->y -1)  || x == (mlx->x -1) )
// 				mlx_put_image_to_window(mlx->mlx, mlx->win, img2, x * TILE, y * TILE);
// 			else
// 				mlx_put_image_to_window(mlx->mlx, mlx->win, img1, x * TILE, y * TILE);
// 			y += 1;
// 		}
// 		y = 0;
// 		x += 1;
// 	}
// }
