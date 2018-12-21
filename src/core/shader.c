/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 04:39:38 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:57:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		load_shader(GLenum type, unsigned int *ref, const char *file_name)
{
	GLchar	*shader_source;

	*ref = glCreateShader(type);
	shader_source = file_to_string(SHADER_PATH, file_name);
	glShaderSource(*ref, 1, (const GLchar *const *)&shader_source, NULL);
	status_gl("Asking for sources", __LINE__, __FILE__);
	glCompileShader(*ref);
	status_gl("Compile shader", __LINE__, __FILE__);
}

void		next_shader(int type, t_shader_lst *e)
{
	e->previous = e;
	e->next = new_shader(type);
	e = e->next;
}

void		get_shaders_from_directory(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;
	char			*ext_str;
	int				ext;
	t_shader_lst	*shader;

	if (!(dir = opendir(SHADER_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext_str = get_extension(file->d_name);
		ext = match_extension_to_enum(ext_str);
		if (ext != INVALID)
		{
			add_to_shader_tally(gl, ext);
			shader = get_curr_shader(gl, ext);
			load_shader(ext, &shader->ref, file->d_name);
			check_shader_compile(shader->ref);
			next_shader(ext, shader);
		}
	}
}

void		init_shader_lst(t_gl *gl)
{
	gl->root_vert_shdr = new_shader(GL_VERTEX_SHADER);
	gl->root_geom_shdr = new_shader(GL_GEOMETRY_SHADER);
	gl->root_frag_shdr = new_shader(GL_FRAGMENT_SHADER);
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_geom_shdr = gl->root_geom_shdr;
	gl->n_vert_shdrs = 0;
	gl->n_frag_shdrs = 0;
	gl->n_geom_shdrs = 0;
}

void		load_shaders(t_gl *gl)
{
	init_shader_lst(gl);
	get_shaders_from_directory(gl);
	gl->shdr_program = glCreateProgram();
	status_gl("Creating program", __LINE__, __FILE__);
	bind_shader(gl->shdr_program,
				gl->root_vert_shdr->ref,
				gl->root_geom_shdr->ref,
				gl->root_frag_shdr->ref);
}
