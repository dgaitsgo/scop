/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:22:17 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 21:28:44 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	extract_indices(t_vector *holder, int *indices, int i, int sign)
{
	holder->x = indices[i] - sign;
	holder->y = indices[i + 1] - sign;
	holder->z = indices[i + 2] - sign;
	holder->w = indices[i + 3] - sign;
}

void	push_left_triangle(
			float *pos,
			int *i_pos,
			t_obj_data *data,
			t_triangle_idx i)
{
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].z);
	push(pos, i_pos, data->vertices[(int)i.temp_i.y + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.y + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.y + i.offset].z);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].z);
}

void	push_right_triangle(
			float *pos,
			int *i_pos,
			t_obj_data *data,
			t_triangle_idx i)
{
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.x + i.offset].z);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.z + i.offset].z);
	push(pos, i_pos, data->vertices[(int)i.temp_i.w + i.offset].x);
	push(pos, i_pos, data->vertices[(int)i.temp_i.w + i.offset].y);
	push(pos, i_pos, data->vertices[(int)i.temp_i.w + i.offset].z);
}

void	order_position(t_vertex_table *v, t_obj_data *data, int sign)
{
	t_triangle_idx	ti;
	float			*pos;
	int				i_index;

	i_index = -4;
	pos = v->positions;
	ti.offset = sign == 1 ? 0 : data->n_vertices;
	while (i_index < data->n_faces)
	{
		i_index += 4;
		extract_indices(&ti.temp_i, data->vert_indices, i_index, sign);
		push_left_triangle(pos, &v->i_pos, data, ti);
		if ((sign == 1 && ti.temp_i.w > 0) || (sign == -1 && ti.temp_i.w < 0))
		{
			push_right_triangle(pos, &v->i_pos, data, ti);
		}
	}
}

void	order_data(
			t_vertex_table *v,
			t_obj_data **data,
			int n_groups,
			int flags)
{
	int			sign;
	int			i;

	i = 0;
	sign = BIT_CHECK(flags, NEGATIVE_INDEXES) ? -1 : 1;
	v->i_pos = -1;
	while (i < n_groups)
	{
		order_position(v, data[i], sign);
		i++;
	}
	v->i_pos = round_up(v->i_pos, 3);
}
