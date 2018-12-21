/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:09:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:57:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

struct s_shader_lst	*new_shader(short type)
{
	struct s_shader_lst	*node;

	node = ft_memalloc(sizeof(t_shader_lst));
	node->type = type;
	if (!node)
		exit(1);
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void				set_standard_shader_uniforms(t_gl *gl)
{
	gl->uniform_refs[MODEL] =
		glGetUniformLocation(gl->shdr_program, "model");
	gl->uniform_refs[OFFSET] =
		glGetUniformLocation(gl->shdr_program, "offset");
	gl->uniform_refs[VIEW] =
		glGetUniformLocation(gl->shdr_program, "view");
	gl->uniform_refs[PROJECTION] =
		glGetUniformLocation(gl->shdr_program, "proj");
	gl->uniform_refs[FADE] =
		glGetUniformLocation(gl->shdr_program, "fade");
	gl->uniform_refs[RENDER_MODE] =
		glGetUniformLocation(gl->shdr_program, "render_mode");
	gl->uniform_refs[SHRINK_FACTOR] =
		glGetUniformLocation(gl->shdr_program, "shrink");
	gl->uniform_refs[EXPLODE_FACTOR] =
		glGetUniformLocation(gl->shdr_program, "explode_factor");
	gl->uniform_refs[MODEL_RADIUS] =
		glGetUniformLocation(gl->shdr_program, "modelBVRadius");
	gl->uniform_refs[INSTANCE_LEN] =
		glGetUniformLocation(gl->shdr_program, "instanceLen");
	status_gl("Uniforms bound", __LINE__, __FILE__);
}

void				associate_standard_uniforms(t_gl *gl,
										t_matrix model,
										t_matrix view,
										t_matrix projection)
{
	glUniformMatrix4fv(gl->uniform_refs[MODEL],
		1, GL_TRUE, &model[0][0]);
	glUniformMatrix4fv(gl->uniform_refs[VIEW],
		1, GL_TRUE, &view[0][0]);
	glUniformMatrix4fv(gl->uniform_refs[PROJECTION],
		1, GL_FALSE, &projection[0][0]);
}

void				bind_shader(GLuint program,
						GLuint vert_ref,
						GLuint geom_ref,
						GLuint frag_ref)
{
	glAttachShader(program, vert_ref);
	status_gl("Attatched vert", __LINE__, __FILE__);
	glAttachShader(program, geom_ref);
	status_gl("Attatched geom", __LINE__, __FILE__);
	glAttachShader(program, frag_ref);
	status_gl("Attatched frag", __LINE__, __FILE__);
	glLinkProgram(program);
	status_gl("Linked Program", __LINE__, __FILE__);
	check_open_gl_program(program);
}
