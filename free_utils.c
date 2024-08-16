/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:45:05 by gartan            #+#    #+#             */
/*   Updated: 2024/08/16 15:19:33 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	make_fail(t_win *mlx)
{
	free_tab(mlx->map, mlx->y);
	free(mlx);
	exit(EXIT_FAILURE);
}