/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:22:17 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 15:27:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	extract_indices(t_vector *holder, int *indices, int i, int sign)
{
	holder->x = indices[i] - sign;
	holder->y = indices[i + 1] - sign;
	holder->z = indices[i + 2] - sign;
	holder->w = indices[i + 3] - sign;

	//printf("%d, %d, %d, %d\n", (int)holder->x, (int)holder->y, (int)holder->z, (int)holder->w);
}

void	push(float *array, int *pos, float item)
{
	(*pos)++;
	array[*pos] = item;
}

void	order_position(t_vertex_table *v, t_obj_data *data, int sign)
{
	t_vector	temp_i;
	float		*pos;
	int			offset;
	int			i_index;
	int			dubya;

	i_index = -4;
	pos = v->positions;
	offset = sign == 1 ? 0 : data->n_vertices;
//	printf("\n n vertices = %d, n vert indices = %d, offset == %d, sign == %d\n",
//	data->n_vertices, data->n_faces, offset, sign);

	while (i_index < data->n_faces)
	{
		i_index += 4;
		extract_indices(&temp_i, data->vert_indices, i_index, sign);
		//printf("%f, %f, %f, %f\n", temp_i.x, temp_i.y, temp_i.z, temp_i.w);

		push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].x);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].y);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].z);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.y + offset].x);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.y + offset].y);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.y + offset].z);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].x);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].y);
		push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].z);

		//printf("Vertex @ %d :  %f, %f, %f\n", (int)temp_i.x + offset, 
		//data->vertices[(int)temp_i.x + offset].x,
		//data->vertices[(int)temp_i.x + offset].y,
		//data->vertices[(int)temp_i.x + offset].z);
	
		//it's a quad
		//make second triangle
		if ((sign == 1 && temp_i.w > 0) || (sign == -1 && temp_i.w < 0))
		{
		//	printf("Impossible to fall in here beacuse w = %f\n", temp_i.w);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].x);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].y);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.x + offset].z);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].x);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].y);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.z + offset].z);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.w + offset].x);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.w + offset].y);
			push(pos, &v->i_pos, data->vertices[(int)temp_i.w + offset].z);
		}
	}
//	v->i_pos += 9;
//	printf("N FACES == %d\n", v->i_pos);
}

void	check_out_floats(float *data, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}\n",
		data[i + 0], data[i + 1], data[i + 2],
		data[i + 3], data[i + 4], data[i + 5],
		data[i + 6], data[i + 7], data[i + 8]);
		i += 9;
	}
}

int round_up(int num, int factor)
{
    return num + factor - 1 - (num - 1) % factor;
}

void	order_data(t_vertex_table *v, t_obj_data **data, int n_groups, int flags)
{
	int			sign;
	int			i;

	i = 0;
	sign = BIT_CHECK(flags, NEGATIVE_INDEXES) ? -1 : 1;
	//printf("Groups == %d\n", n_groups);
	v->i_pos = -1;
	while (i < n_groups)
	{
		order_position(v, data[i], sign);
	//	check_out_floats(v[i]->positions, v[i]->i_pos);
	/*
		if (BIT_CHECK(flags, TEXT_COORDS_DEFINED))
  	
			order(v->text_coords, data[i], j, sign);
		if (BIT_CHECK(flags, NORMALS_DEFINED))
			order(v->normals, data[i], j, sign);
		j += 4;
	*/
		i++;
	}
	v->i_pos = round_up(v->i_pos, 3);
}
