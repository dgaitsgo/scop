/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curr_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:56:37 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 13:14:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint			get_curr_shader_ref(t_gl *gl, int shader_type)
{
	GLuint	ref;

	if (shader_type == GL_VERTEX_SHADER)
		ref = gl->curr_vert_shdr->ref;
	else if (shader_type == GL_GEOMETRY_SHADER)
		ref = gl->curr_geom_shdr->ref;
	else if (shader_type == GL_FRAGMENT_SHADER)
		ref = gl->curr_frag_shdr->ref;
	return (ref);
}

t_shader_lst	*get_curr_shader(t_gl *gl, int shader_type)
{
	if (shader_type == GL_VERTEX_SHADER)
		return (gl->curr_vert_shdr);
	else if (shader_type == GL_GEOMETRY_SHADER)
		return (gl->curr_geom_shdr);
	else if (shader_type == GL_FRAGMENT_SHADER)
		return (gl->curr_frag_shdr);
	return (NULL);
}
