/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:50:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/29 14:59:16 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		l;
	int		h;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		close(t_vars *vars);
void	incrust(t_vars vars, int x, int y);

#endif