/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:20:34 by jguthert          #+#    #+#             */
/*   Updated: 2016/09/11 18:03:17 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perco.h"

static void fill_arr(t_arr *arr)
{
	int	i;
	int	m;

	m = arr->n * arr->n;
	i = 0;
	while (i < m)
	{
		arr->id[i] = i;
		arr->sz[i] = 1;
		arr->blocked[i] = 1;
		i++;
	}
}

int			init_arrays(int n, t_arr *arr)
{
	int	*id;
	int	*sz;
	int	*blocked;

	id = (int *)malloc(sizeof(int) * (n * n + 1));
	sz = (int *)malloc(sizeof(int) * (n * n + 1));
	blocked = (int *)malloc(sizeof(int) * (n * n + 1));
	if (id == NULL || sz == NULL)
		return (0);
	arr->id = id;
	arr->sz = sz;
	arr->blocked = blocked;
	arr->n = n;
	fill_arr(arr);
	return (1);
}
