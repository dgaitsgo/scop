/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 04:39:38 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/29 00:14:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

struct s_shader_lst		*new_shader(short type)
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


void		set_standard_shader_uniforms(t_gl *gl)
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

/*
	TO DO: 
	typedef struct s_uniform {
		unsigned int	*locations;
		int				*types;
		void 			*uniforms;
	}
*/

void		associate_standard_uniforms(t_gl *gl,
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

void		bind_shader(GLuint program,
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

void		load_shader(GLenum type, unsigned int *ref, const char *file_name)
{
	GLchar 	*shader_source;

	*ref = glCreateShader(type);
	shader_source = file_to_string(SHADER_PATH, file_name);
	glShaderSource(*ref, 1, (const GLchar *const *)&shader_source, NULL);
	status_gl("Asking for sources", __LINE__, __FILE__);
	glCompileShader(*ref);
	status_gl("Compile shader", __LINE__, __FILE__);

	//free(shader_source)
}

void			next_shader(int type, t_shader_lst *e)
{
	e->previous = e;
	e->next = new_shader(type);
	e = e->next;
}

/*
	This is organized in a shitty way.

	there should be 1 shader program per node, and the programs 
	should switch not individual components.
	They could be associated by name e.g:
		simple.vert
		simple.geom
		simple.frag

		complicated.vert
		complicated.frag
*/

void				get_shaders_from_directory(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;		
	char			*ext_str;
	int				ext;
	t_shader_lst	*shader;

	/*Should check flags if at least one of each type of shader is present*/
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
		/*	Also, gets first shader running*/
	gl->shdr_program = glCreateProgram();
	status_gl("Creating program", __LINE__, __FILE__);
	bind_shader(gl->shdr_program,
				gl->root_vert_shdr->ref,
				gl->root_geom_shdr->ref,
				gl->root_frag_shdr->ref);
}
