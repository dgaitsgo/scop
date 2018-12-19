/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:37:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 22:45:10 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				init_getline(t_getline *line)
{
	line->s = NULL;
	line->n = 0;
}

struct s_group_lst	*new_group(void)
{
	struct s_group_lst *node;

	node = ft_memalloc(sizeof(t_group_lst));
	if (!node)
		exit(1);
	node->quads = 0;
	node->n_vertices = 0;
	node->n_normals = 0;
	node->n_text_coords = 0;
	node->n_faces = 0;
	node->next = NULL;
	return (node);
}
