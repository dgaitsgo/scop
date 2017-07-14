/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_gl_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:50:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 15:35:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	check_shader_compile(GLuint shader_name)
{
	GLint	status;
	char	*buffer = malloc(512);

	glGetShaderiv(shader_name, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(shader_name, 512, NULL, buffer);
		printf("%s\n", buffer);
		exit(1);
	}
	free(buffer);
}

void	get_active_uniforms(GLuint program, GLuint n_uniforms)
{
	char	*buffer = malloc(512);
	int		i;

	i = 0;
	printf("Active uniforms = %d\n", n_uniforms);
	while (i < n_uniforms)
	{
		glGetActiveUniform(	program,
							i,
							512,
							NULL,
						 	NULL,
							NULL,
							buffer);
		printf("Name of uniform : %s\n", buffer);
		i++;
	}
	free(buffer);
}

void	check_open_gl_program(GLuint program)
{
	int		ret;

	printf("\n");
	printf("OpenGL Program Information :\n");
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &ret);
	get_active_uniforms(program, ret);
	glGetProgramiv(program, GL_ATTACHED_SHADERS, &ret);
	printf("Attatched shaders = %d\n", ret);
	glGetProgramiv(program, GL_LINK_STATUS, &ret);
	if (ret == GL_FALSE)
		printf("Link failed!\n");
	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &ret);
	if (ret == GL_FALSE)
		printf("Invalid program!\n");
	printf("\n");
}

void	status_gl(const char *message, int line, char *file)
{
	int	err;

	if ((err = glGetError()) != GL_NO_ERROR)
	{
		printf("Error : %d at  %d, %s\n", err, line, file);
		exit(1);
	}
	else
		printf("Succeded : %s\n", message);
}
