/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_buffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:57:59 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 11:58:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
