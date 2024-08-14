/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:02 by gartan            #+#    #+#             */
/*   Updated: 2024/08/14 23:27:55 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup_SL(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i])
		i++;
	result = (char *) malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	if (result[i - 1] == '\n')
		result[i - 1] = '\0';
	return (result);
}

char	**copy_tab(char **map)
{
	char	**tab;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tab = ft_calloc(i, sizeof(char*));
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strdup(map[i]);
		i++;
	}
	return (tab);
}
