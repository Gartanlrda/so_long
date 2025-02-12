/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:05 by gartan            #+#    #+#             */
/*   Updated: 2024/08/16 15:47:56 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	close_win(t_win *win)
{
	mlx_destroy_image(win->mlx, win->lib.char_exit.img);
	mlx_destroy_image(win->mlx, win->lib.character.img);
	mlx_destroy_image(win->mlx, win->lib.collectible.img);
	mlx_destroy_image(win->mlx, win->lib.exit.img);
	mlx_destroy_image(win->mlx, win->lib.floor.img);
	mlx_destroy_image(win->mlx, win->lib.wall.img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free_tab(win->map, win->y);
	free(win->mlx);
	free(win);
	return (0);
}

void	ft_put_pixel(t_win *win, int x, int y, int color)
{
	t_img	img;

	img.img = mlx_new_image(win->mlx, win->x, win->y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
		&img.line_len, &img.endian);
	my_mlx_pixel_put(&img, x, y, color);
	mlx_put_image_to_window(win->mlx, win->win, img.img, 0, 0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcheckstr(char *str, char *checker)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlens(str) && checker[j])
	{
		if (str[i] == checker[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if (j == ft_strlens(checker))
		return (0);
	else
		return (1);
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
