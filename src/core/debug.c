/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 01:32:49 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/27 17:26:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


//void	log(char *message, void *value, int type)
//{
//	fprintf(scop_log, "%s : %c" message, );
//}


void		check_groups(t_group_lst *group)
{
	int	i;

	i = 0;
	while (group != NULL)
	{
		printf("Group %d\n", i);
		printf("n vertices =\t%d\n", group->n_vertices);
		printf("n normals =\t%d\n", group->n_normals);
		printf("n text coords = %d\n", group->n_text_coords);
		i++;
		group = group->next;
	}
}
