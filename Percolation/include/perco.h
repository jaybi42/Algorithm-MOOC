/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/09/11 17:57:45 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCO_H
# define PERCO_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_arr
{
	int				n;
	int				*id;
	int				*sz;
	int				*blocked;
}					t_arr;

/*
**Name: Parsing
**File:
**Desc:
*/

int					init_arrays(int n, t_arr *arr);
void				do_union(int id1, int id2, t_arr *arr);
int					get_root(int i, t_arr *arr);

#endif
