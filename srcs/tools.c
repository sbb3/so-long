/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:13:25 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 15:35:36 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	map_width(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	map_height(char *s[])
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	search_map(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	collect_count(char *s[])
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == 'C')
				count++;
	}
	return (count);
}
