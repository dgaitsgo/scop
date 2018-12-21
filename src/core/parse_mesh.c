/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:23:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 21:46:52 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			push_coord(t_getline line, t_obj_data **obj_data,
				int i_group, int flags)
{
	int last_read_was_face;

	last_read_was_face = 0;
	if (line.s[0] == 'v' && line.s[1] == 't')
		push_text_coord(obj_data[i_group], line.s);
	else if (line.s[0] == 'v' && line.s[1] == 'n')
		push_normal(obj_data[i_group], line.s);
	else if (line.s[0] == 'f')
	{
		last_read_was_face = 1;
		push_face(obj_data[i_group], line.s, flags);
	}
	return (last_read_was_face);
}

void		write_in_data(t_obj_data **obj_data, FILE *fd, int flags)
{
	t_getline	line;
	int			i_group;
	int			last_read_was_face;

	last_read_was_face = 0;
	i_group = 0;
	init_getline(&line);
	while (getline(&line.s, &line.n, fd) > 0)
	{
		if (line.s[0] == 'v' && line.s[1] == ' ')
		{
			if (BIT_CHECK(flags, NEGATIVE_INDEXES) && last_read_was_face == 1)
			{
				i_group++;
				last_read_was_face = 0;
			}
			push_vertex(obj_data[i_group], line.s);
		}
		last_read_was_face = push_coord(line, obj_data, i_group, flags);
	}
}

void		load_obj(t_model *model, FILE *fd)
{
	t_group_lst		*group;

	group = model->root_group;
	count_group_data(fd, group, &model->n_groups, &model->flags);
	check_flags(model->flags);
	model->obj_data = fetch_obj_data_mem(model->root_group, model->n_groups);
	fseek(fd, 0, SEEK_SET);
	write_in_data(model->obj_data, fd, model->flags);
	model->vertex_table =
		fetch_vertex_table_mem(model->obj_data, model->n_groups, model->flags);
	order_data(model->vertex_table, model->obj_data,
				model->n_groups, model->flags);
	bound_model(model);
}
