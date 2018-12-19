/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 02:58:21 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 11:48:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		only_geometry_face_push(t_obj_data *data, char *line)
{
	data->n_faces += 4;
	sscanf(line, "f %d %d %d %d",
	&data->vert_indices[data->n_faces + 0],
	&data->vert_indices[data->n_faces + 1],
	&data->vert_indices[data->n_faces + 2],
	&data->vert_indices[data->n_faces + 3]);
}

void		all_verts_defined_face_push(t_obj_data *data, char *line)
{
	data->n_faces += 4;
	sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
	&data->vert_indices[data->n_faces + 0],
	&data->text_indices[data->n_faces + 0],
	&data->norm_indices[data->n_faces + 0],
	&data->vert_indices[data->n_faces + 1],
	&data->text_indices[data->n_faces + 1],
	&data->norm_indices[data->n_faces + 1],
	&data->vert_indices[data->n_faces + 2],
	&data->text_indices[data->n_faces + 2],
	&data->norm_indices[data->n_faces + 2],
	&data->vert_indices[data->n_faces + 3],
	&data->text_indices[data->n_faces + 3],
	&data->norm_indices[data->n_faces + 3]);
}

void		only_norms_face_push(t_obj_data *data, char *line)
{
	data->n_faces += 4;
	sscanf(line, "f %d//%d %d//%d %d//%d %d//%d",
	&data->vert_indices[data->n_faces + 0],
	&data->norm_indices[data->n_faces + 0],
	&data->vert_indices[data->n_faces + 1],
	&data->norm_indices[data->n_faces + 1],
	&data->vert_indices[data->n_faces + 2],
	&data->norm_indices[data->n_faces + 2],
	&data->vert_indices[data->n_faces + 3],
	&data->norm_indices[data->n_faces + 3]);
}

void		only_texts_face_push(t_obj_data *data, char *line)
{
	data->n_faces += 4;
	sscanf(line, "f %d/%d %d/%d %d/%d %d/%d",
	&data->vert_indices[data->n_faces + 0],
	&data->text_indices[data->n_faces + 0],
	&data->vert_indices[data->n_faces + 1],
	&data->text_indices[data->n_faces + 1],
	&data->vert_indices[data->n_faces + 2],
	&data->text_indices[data->n_faces + 2],
	&data->vert_indices[data->n_faces + 3],
	&data->text_indices[data->n_faces + 3]);
}

void		push_face(t_obj_data *data, char *line, int flags)
{
	if (BIT_CHECK(flags, ONLY_GEOMETRY))
		only_geometry_face_push(data, line);
	if (BIT_CHECK(flags, ALL_VERTS_DEFINED))
		all_verts_defined_face_push(data, line);
	if (!BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		((BIT_CHECK(flags, NORMALS_DEFINED))))
		only_norms_face_push(data, line);
	if (BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		(!(BIT_CHECK(flags, NORMALS_DEFINED))))
		only_texts_face_push(data, line);
}
