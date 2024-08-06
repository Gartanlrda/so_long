/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:03:27 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 17:07:55 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
# include "libft/libft.h"

t_win	new_window(int w, int h, char *str)
{
	void *	mlx_ptr;
	t_win	win;

	mlx_ptr = mlx_init();
	win = (t_win){mlx_ptr,
		mlx_new_window(mlx_ptr, w, h, str),
		w,
		h,
		(t_rect){0, 0, w, h, 0x00a4ff32}};
	return (win);
}

void	destroy_window(t_win w)
{
	if (w.mlx_ptr && w.win_ptr)
		mlx_destroy_window(w.mlx_ptr, w.win_ptr);
	if (w.mlx_ptr)
		free(w.mlx_ptr);
}
