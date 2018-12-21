/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_vects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:18:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:53:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		push_vertex(t_obj_data *data, char *line)
{
	data->n_vertices++;
	sscanf(line, "v %e %e %e",
	&data->vertices[data->n_vertices].x,
	&data->vertices[data->n_vertices].y,
	&data->vertices[data->n_vertices].z);
}

void		push_text_coord(t_obj_data *data, char *line)
{
	data->n_text_coords++;
	sscanf(line, "vt %e %e %e",
	&data->text_coords[data->n_text_coords].x,
	&data->text_coords[data->n_text_coords].y,
	&data->text_coords[data->n_text_coords].z);
}

void		push_normal(t_obj_data *data, char *line)
{
	data->n_normals++;
	sscanf(line, "vn %e %e %e",
	&data->normals[data->n_normals].x,
	&data->normals[data->n_normals].y,
	&data->normals[data->n_normals].z);
}
