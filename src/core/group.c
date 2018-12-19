/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:29:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 13:41:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_group_lst		*update_group(t_group_lst *group,
								int *n_groups)
{
	group->next = new_group();
	(*n_groups)++;
	return (group->next);
}

int				check_letter(t_getline line, t_group_lst *group,
							int last_read_was_face, int *flags)
{
	if (line.s[0] == 'v' && line.s[1] == 't')
		group->n_text_coords++;
	else if (line.s[0] == 'v' && line.s[1] == 'n')
		group->n_normals++;
	else if (line.s[0] == 'f')
	{
		last_read_was_face = 1;
		group->n_faces++;
		if (group->n_faces == 1)
			check_face_flags(line.s, flags);
		if (count_char('/', line.s) > 6)
			group->quads++;
	}
	return (last_read_was_face);
}

void			count_group_data(FILE *fd,
							t_group_lst *group, int *n_groups, int *flags)
{
	t_getline	line;
	int			last_read_was_face;
	int			yep;

	yep = 0;
	last_read_was_face = 0;
	init_getline(&line);
	while (getline(&line.s, &line.n, fd) > 0)
	{
		if (line.s[0] == 'v' && line.s[1] == ' ')
		{
			if (BIT_CHECK(*flags, NEGATIVE_INDEXES) && last_read_was_face == 1)
			{
				group = update_group(group, n_groups);
				last_read_was_face = 0;
			}
			group->n_vertices++;
		}
		else
			last_read_was_face = check_letter(line, group,
				last_read_was_face, flags);
		yep++;
	}
}
