/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:02:19 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 17:06:48 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_rect
{
	int	x;
	int	y;
	int	size_w;
	int	size_h;
	int	color;
}				t_rect;

typedef struct s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}				t_circle;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_rect	bg;
}				t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

/*Window and Images*/
t_win	new_window(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
void	draw_rect(t_rect rect, t_img img);
void	draw_circle(t_circle circle, t_img img);
t_list	*ft_lstget(t_list *lst, int index);
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr);
void	destroy_image(t_img img);
void	destroy_window(t_win w);

#endif