/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:31:59 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 20:08:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_model(t_model *model)
{
	model->flags = 0;
	zero_matrix(model->model);
	model->root_group = new_group();
	model->n_groups = 1;
}

void	bound_model(t_model *model)
{
	t_vector			curr;
	t_bounding_sphere	*bv;
	int					i;
	int					j;

	i = 0;
	bv = &model->bv;
	set_vector(&bv->min, FLT_MAX, FLT_MAX, FLT_MAX);
	set_vector(&bv->max, FLT_MIN, FLT_MIN, FLT_MIN);
	j = 0;
	while (j < model->vertex_table->i_pos)
	{
		curr.x = model->vertex_table->positions[j + 0];
		curr.y = model->vertex_table->positions[j + 1];
		curr.z = model->vertex_table->positions[j + 2];
		bv->min = vector_min(curr, bv->min);
		bv->max = vector_max(curr, bv->max);
		j += 3;
	}
	bv->center.x = (bv->max.x + bv->min.x) / 2;
	bv->center.y = (bv->max.y + bv->min.y) / 2;
	bv->center.z = (bv->max.z + bv->min.z) / 2;
	bv->diameter = euclidean_distance3d(bv->max, bv->min);
}
