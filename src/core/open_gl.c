/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openGL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:36:43 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 01:29:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint		get_curr_shader_ref(t_gl *gl, int shader_type)
{
	GLuint 	ref;

	if (shader_type == GL_VERTEX_SHADER)
		ref = gl->curr_vert_shdr->ref;
	else if (shader_type == GL_GEOMETRY_SHADER)
		ref = gl->curr_geom_shdr->ref;
	else if (shader_type == GL_FRAGMENT_SHADER)
		ref = gl->curr_frag_shdr->ref;
	return (ref);
}

t_shader_lst *get_curr_shader(t_gl *gl, int shader_type)
{
	if (shader_type == GL_VERTEX_SHADER)
		return (gl->curr_vert_shdr);
	else if (shader_type == GL_GEOMETRY_SHADER)
		return (gl->curr_geom_shdr);
	else if (shader_type == GL_FRAGMENT_SHADER)
		return (gl->curr_frag_shdr);
	return (NULL);
}

void	add_to_shader_tally(t_gl *gl, int shader_type)
{
	if (shader_type == GL_VERTEX_SHADER)
		gl->n_vert_shdrs++;
	else if (shader_type == GL_GEOMETRY_SHADER)
		gl->n_geom_shdrs++;
	else if (shader_type == GL_FRAGMENT_SHADER)
		gl->n_frag_shdrs++;
}

void		clear_open_gl(t_vector color, GLbitfield mask)
{
	rgb_to_normal(&color);
	glClearColor(color.x, color.y, color.z, 1.0);
	glClear(mask);
}

void		generate_vbo(GLuint *ref, int n_faces, GLfloat *vertices)
{
	glGenBuffers(1, ref);
	glBindBuffer(GL_ARRAY_BUFFER, *ref);
	glBufferData(GL_ARRAY_BUFFER,
	sizeof(GLfloat) * n_faces, vertices, GL_STATIC_DRAW);
	status_gl("Added VBO", __LINE__, __FILE__);
}

void		generate_vao(GLuint *ref)
{
	glGenVertexArrays(1, ref);
	glBindVertexArray(*ref);
	status_gl("Added VAO", __LINE__, __FILE__);
}

void		default_vertex_attributes(void)
{	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	status_gl("Default vertex Attributes", __LINE__, __FILE__);
}

void		init_open_gl(t_scop *scop)
{
	int i;

	i = 0;
	scop->gl.vbo = ft_memalloc(sizeof(GLuint) * scop->model.n_groups);
	generate_vbo(	&scop->gl.vbo[i],
						scop->model.vertex_table->i_pos,
						scop->model.vertex_table->positions);
	glEnable(GL_DEPTH_TEST);
	generate_vao(&scop->gl.vao);
	default_vertex_attributes();
}
