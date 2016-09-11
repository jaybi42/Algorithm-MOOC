/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_union.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:28:00 by jguthert          #+#    #+#             */
/*   Updated: 2016/09/11 18:11:10 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perco.h"

int		find(int id1, int id2, t_arr *arr)
{
	return (get_root(id1, arr) == get_root(id2, arr))
}

int		get_root(int i, t_arr *arr)
{
	while (arr->id[i] != i)
	{
		arr->id[i] = arr->id[arr->id[i]];
		i = arr->id[i];
	}
	return (i);
}

void	do_union(int id1, int id2, t_arr *arr)
{
	int i;
	int j;

	i = get_root(id1, arr);
	j = get_root(id2, arr);
	if (i == j)
		return ;
	if (arr->sz[i] > arr->sz[j])
	{
		arr->id[j] = i;
		arr->sz[i] += arr->sz[j];
	}
	else
	{
		arr->id[i] = j;
		arr->sz[j] += arr->sz[i];
	}
}
