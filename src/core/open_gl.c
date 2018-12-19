/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openGL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:36:43 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 13:17:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		add_to_shader_tally(t_gl *gl, int shader_type)
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
	generate_vbo(&scop->gl.vbo[i],
					scop->model.vertex_table->i_pos,
					scop->model.vertex_table->positions);
	glEnable(GL_DEPTH_TEST);
	generate_vao(&scop->gl.vao);
	default_vertex_attributes();
}

void		set_texture(t_gl *gl)
{
	int tex_loc;

	tex_loc = glGetUniformLocation(gl->shdr_program, "basic_texture");
	glUseProgram(gl->shdr_program);
	glUniform1i(tex_loc, 0);
}
