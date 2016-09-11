/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:44:25 by jguthert          #+#    #+#             */
/*   Updated: 2016/09/11 18:14:15 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perco.h"

/*
** Init the arrays with id and weight tree 1
** Check if neighbors exists and union if open cases
**
*/

static void is_percolate(t_arr *arr)
{
	int v_top;
	int v_bot;

	i = 0;
	while (i < 25)
	{
		if (arr->blocked[i] == 0)
			;
	}
	if (find(v_top, v_bot, arr) == 1)
		ft_putendl("Percolate !");
	else
		ft_putendl("Not enough empty case...");
}

static int	init_union(char *line, t_arr *arr)
{
	int		x;
	int		y;
	int		id;

	x = ft_atoi(line);
	y = ft_atoi(line + ft_nbrlen(x));
	id = arr->n * y + x;
	arr->blocked[id] = 0;
	if (x - 1 > 0 && arr->blocked[arr->n * y + (x - 1)] == 0)
		do_union(arr->n * y + (x - 1), id, arr);
	if (y - 1 > 0 && arr->blocked[arr->n * (y - 1) + x] == 0)
		do_union(arr->n * (y - 1) + x, id, arr);
	if (x + 1 < arr->n && arr->blocked[arr->n * y + (x + 1)] == 0)
		do_union(arr->n * y + (x + 1), id, arr);
	if (y + 1 > arr->n && arr->blocked[arr->n * (y + 1) + x] == 0)
		do_union(arr->n * (y + 1) + x, id, arr);
	return (1);
}

static int	percolation(char *file)
{
	int		fd;
	char	*line;
	t_arr	arr;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	if (get_next_line(fd , &line) == -1)
		return (ERROR);
	if (!init_arrays(ft_atoi(line), &arr))
		return (ERROR);
	while (get_next_line(fd , &line) > 0)
	{
		if (!init_union(line, &arr))
			return (ERROR);
	}
	is_percolate(&arr);
//	free_tab
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		percolation(av[1]);
	return (0);
}
