/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:32:48 by gartan            #+#    #+#             */
/*   Updated: 2024/08/15 05:03:23 by gartan           ###   ########.fr       */
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

void	make_imglib(t_win *mlx)
{
	char	*floor = "./Tileset/grass_floor.xpm";
	char	*wall = "./Tileset/tree_wall.xpm";
	char	*collectible = "./Tileset/collectible.xpm";
	int		img_width;
	int		img_height;

	make_imglib2(mlx);
	mlx->lib.floor.img = mlx_xpm_file_to_image\
		(mlx->mlx, floor, &img_width, &img_height);
	mlx->lib.wall.img = mlx_xpm_file_to_image\
		(mlx->mlx, wall, &img_width, &img_height);
	mlx->lib.collectible.img = mlx_xpm_file_to_image\
		(mlx->mlx, collectible, &img_width, &img_height);
}

void	make_imglib2(t_win *mlx)
{
	char	*character = "./Tileset/character.xpm";
	char	*exit = "./Tileset/exit.xpm";
	char	*char_exit = "./Tileset/char_exit.xpm";
	int		img_width;
	int		img_height;

	mlx->lib.character.img = mlx_xpm_file_to_image\
		(mlx->mlx, character, &img_width, &img_height);
	mlx->lib.exit.img = mlx_xpm_file_to_image\
		(mlx->mlx, exit, &img_width, &img_height);
	mlx->lib.char_exit.img = mlx_xpm_file_to_image\
		(mlx->mlx, char_exit, &img_width, &img_height);
}

void	make_map(t_win *mlx)
{
	char	**map;
	t_coord	c;
	
	map = copy_tab(mlx->map);
	c.x = 0;
	c.y = 0;
	get_character(map, &c);
	resize_map(mlx, map, c);
	free_tab(map, mlx->y);
	final_touch(mlx);
}
