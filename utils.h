/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:54 by gartan            #+#    #+#             */
/*   Updated: 2024/08/07 12:25:47 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include "so_long.h"
# include "animation.h"

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
	int		h;
	int		w;
	int		color;
}				t_win;

int		close_win(t_win *win);
void	ft_put_pixel(t_win *win, int x, int y, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_win *win);
int		create_trgb(int t, int r, int g, int b);
void	ft_fullscreen(t_win win);

#endif