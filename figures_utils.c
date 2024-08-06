/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:18:14 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 16:29:18 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
# include "libft/libft.h"

void	draw_rect(t_rect rect, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < rect.size_h && i + rect.y < img.h)
	{
		j = 0;
		while (j < rect.size_w && j + rect.x < img.w)
		{
			put_pixel_img(img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_circle circle, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < circle.radius * 2 && i + circle.y < img.h)
	{
		j = 0;
		while (j < circle.radius * 2 && j + circle.x < img.w)
		{
			if (((j - circle.radius) * (j - circle.radius)) + ((i - circle.radius) * (i - circle.radius)) < (circle.radius * circle.radius))
				put_pixel_img(img, j + circle.x, i + circle.y, circle.color);
			j++;
		}
		i++;
	}
}
