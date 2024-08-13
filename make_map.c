/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:32:48 by gartan            #+#    #+#             */
/*   Updated: 2024/08/13 11:54:58 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup_SL(const char *s)
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


void	coord_map(char *path, t_win *mlx)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (mlx->x == 0)
			mlx->x = (ft_strlen(line) - 1);
		mlx->y++;
		free(line);
	}
	close(fd);
	return ;
}

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
		// printf("line = %s\n", line);
		mlx->map[i] = ft_strdup_SL(line);
		i++;
		free(line);
	}
	close(fd);
	return ;
}

// int	map_check(t_win *mlx)
// {
	
// }

void	make_map(t_win *mlx, void *img1, void *img2)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// printf("width %d\n", mlx->x);
	// printf("height %d\n", mlx->y);
	while (x < mlx->x)
	{
		while (y < mlx->y)
		{
			if (x == 0 || y == 0 || y == (mlx->y -1)  || x == (mlx->x -1) )
				mlx_put_image_to_window(mlx->mlx, mlx->win, img2, x * TILE, y * TILE);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, img1, x * TILE, y * TILE);
			y += 1;
		}
		y = 0;
		x += 1;
	}
}
