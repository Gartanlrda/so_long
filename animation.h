/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:32:10 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 17:07:20 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "utils.h"
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>

enum fig_type
{
	CIRCLE,
	RECT
};

typedef struct s_frame
{
	int	x;
	int	y;
	int	color;
	int	figure_size;
}				t_frame;

typedef struct s_animation
{
	t_list			*frames;
	enum fig_type	fig_type;
	t_frame			current_frame;		// The configuration of the current frame
	int				delay;				// How many fps it takes to change animation frams
	int				_tmp_delay;			// Delay Iterator
	int				current_frame_num;	// Which frame is selected
	int				fps;				// Frames per second, this could be delayed
	int				last_updated;		// When was the last update
	int				frame_count;		// The frame count
}				t_animation;

typedef struct s_animator
{
	t_list *	animations;
	t_win *		win;
	t_img *		img;
}				t_animator;

int			update(t_animator *a);
t_animation	*semaphore(int delay, int fps);
int destroy_animator(t_animator * a);

#endif