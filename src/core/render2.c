/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:43:50 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 13:05:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw_routine(t_scop *scop)
{
	int			i;
	t_vector	sky;

	i = 0;
	set_vector(&sky, 19, 12, 30);
	clear_open_gl(sky, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	set_texture(&scop->gl);
	glUseProgram(scop->gl.shdr_program);
	glBindVertexArray(scop->gl.vao);
	glDrawArraysInstanced(GL_TRIANGLES,
					0,
					scop->model.vertex_table->i_pos / 3,
					scop->instance_len * scop->instance_len);
	i++;
}
