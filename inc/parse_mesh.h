/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:05:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:53:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_MESH_H
# define __PARSE_MESH_H

enum			e_vertex_types
{
	VERT_V,
	TEXT_V,
	NORM_V,
};

typedef struct	s_getline
{
	char		*s;
	size_t		n;
}				t_getline;

void			init_getline(t_getline *line);

#endif
