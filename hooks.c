/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:27:59 by gartan            #+#    #+#             */
/*   Updated: 2024/08/13 16:49:28 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		close_win(win);
	else
		ft_printf("keybind: %i\n", keycode);
	return (0);
}