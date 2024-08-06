/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:04:01 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 17:07:13 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
# include "libft/libft.h"

static t_frame * new_frame(t_frame frame)
{
	t_frame * f;

	f = (t_frame *)ft_calloc(sizeof(t_frame), 1);
	if (!f)
		return (NULL);
	*f = frame;
	return (f);
}

// t_animation *orbit(int delay, int fps)
// {
// 	t_animation	*a;
// 	int			i;
// 	t_frame		*fs[360];

// 	a = (t_animation *)ft_calloc(sizeof(t_animation), 1);
// 	if (!a)
// 		return (NULL);
// 	i = -1;
// 	while (++i < 360)
// 		fs[i] = new_frame((t_frame){cos(deg_to_rad(i)) * 130 + 135, sin(deg_to_rad(i)) * 130 + 135, rand(), 15});
// 	*a = (t_animation){NULL, CIRCLE, *fs[0], delay, 0, 0, fps, 0, 0};
// 	i = -1;
// 	while (++i < 360)
// 		ft_lstadd_back(&a->frames, ft_lstnew(fs[i]));
// 	return (a);
// }

t_animation *semaphore(int delay, int fps)
{
	t_animation	*a;
	int			i;
	t_frame		*fs[192];

	a = (t_animation *)ft_calloc(sizeof(t_animation), 1);
	if (!a)
		return (NULL);
	i = -1;
	while (++i < 50)
		fs[i] = new_frame((t_frame){20, 160, 0x00d4180b, 20});
	fs[i++] = new_frame((t_frame){20, 160, 0, 20});
	fs[i++] = new_frame((t_frame){20, 160, 0x00d4180b, 20});
	fs[i] = new_frame((t_frame){20, 160, 0, 20});
	while (++i < 103)
		fs[i] = new_frame((t_frame){20, 200, 0x00ff6803, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0x00ff6803, 20});
	fs[i] = new_frame((t_frame){20, 200, 0, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0x00ff6803, 20});
	fs[i] = new_frame((t_frame){20, 200, 0, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0x00ff6803, 20});
	fs[i++] = new_frame((t_frame){20, 200, 0, 20});
	fs[i] = new_frame((t_frame){20, 200, 0x00ff6803, 20});
	while (++i < 192)
		fs[i] = new_frame((t_frame){20, 230, 0x0028e813, 20});
	*a = (t_animation){NULL, CIRCLE, *fs[0], delay, 0, 0, fps, 0, 0};
	i = -1;
	while (++i < 192)
		ft_lstadd_back(&a->frames, ft_lstnew(fs[i]));
	return (a);
}

