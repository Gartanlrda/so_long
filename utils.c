/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:43 by gartan            #+#    #+#             */
/*   Updated: 2024/08/06 15:42:15 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


t_list		*ft_lstget(t_list *lst, int index)
{
	t_list	*n;
	int		i;

	i = 0;
	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (i >= index)
			return (n);
		n = n->next;
		i++;
	}
	return (NULL);
}
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content, ptr);
		temp = temp->next;
	}
}
