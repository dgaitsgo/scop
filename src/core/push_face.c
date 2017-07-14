/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 02:58:21 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 15:24:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	debug_face(t_obj_data *data)
{
	printf("f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
	data->vert_indices[data->n_faces + 0],
	data->text_indices[data->n_faces + 0],
	data->norm_indices[data->n_faces + 0],
	data->vert_indices[data->n_faces + 1],
	data->text_indices[data->n_faces + 1],
	data->norm_indices[data->n_faces + 1],
	data->vert_indices[data->n_faces + 2],
	data->text_indices[data->n_faces + 2],
	data->norm_indices[data->n_faces + 2],
	data->vert_indices[data->n_faces + 3],
	data->text_indices[data->n_faces + 3],
	data->norm_indices[data->n_faces + 3]);	
}

void	only_geometry_face_push(t_obj_data *data, char *line)
{
	data->n_faces += 4;
	sscanf(line, "f %d %d %d %d",
	&data->vert_indices[data->n_faces + 0],
	&data->vert_indices[data->n_faces + 1],
	&data->vert_indices[data->n_faces + 2],
	&data->vert_indices[data->n_faces + 3]);
}

void	all_verts_defined_face_push(t_obj_data *data, char *line)
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

void	only_norms_face_push(t_obj_data *data, char *line)
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


/*
		If textures are missing, sometimes there is no
	extra '/' at the end of the tupple.
*/

void	only_texts_face_push(t_obj_data *data, char *line)
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

	printf("NFACES = %d\n", data->n_faces);
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
	/*DEBUG *///	debug_face(data);
}
