/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:54 by gartan            #+#    #+#             */
/*   Updated: 2024/08/13 18:06:34 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include "so_long.h"
# include "libft/ft_printf.h"

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		collectibles;
	int		color;
	char	**map;
}				t_win;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_imglib
{
	t_img	*wall;
	t_img	*floor;
	t_img	*collectible;
	t_img	*character;
	t_img	*exit;
	t_img	*char_exit;
}				t_imglib;

int		close_win(t_win *win);
void	ft_put_pixel(t_win *win, int x, int y, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_win *win);
void	coord_map(char *path, t_win *mlx);
void	copy_map(char *path, t_win *mlx);
char	*ft_strdup_SL(const char *s);
int		flood_fill(t_win *mlx);
void	fill_possible(char **map, t_coord c, t_win *mlx);
void	get_character(char **map, t_coord *c);
char	**copy_tab(char **map);
void	free_tab(char **tab, int size);
int		global_map_check(t_win *mlx);
int		map_doable(char **map, t_win mlx);
int		map_dimension(t_win *mlx);
int		map_valid_char(t_win *mlx);
int		ft_strcheckstr(char *str, char *checker);
void	count_collectibles(t_win *mlx);
int		map_missing_element(t_win *mlx);
void	check_elements(char c, int *P, int *C, int *E);
int		check_border(t_win *win);
void	make_imglib(t_imglib *imglib, t_win *mlx);
void	make_imglib2(t_imglib *imglib, t_win *mlx);
void	*find_img(char c, t_imglib imglib);
void	make_map(t_win *mlx, t_imglib *imglib);

#endif