/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 10:52:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	polygon_mode(int pm)
{
	if (pm == 1)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void	look_at_cont(t_camera *c, int handedness)
{
	if (handedness == LH)
		look_at_lh(c->view,
				c->position,
			vector_add(c->position, c->direction),
				c->up);
	else if (handedness == RH)
		look_at_rh(c->view,
				c->position,
				vector_add(c->position, c->direction),
				c->up);
}

void	center_model(t_model *model)
{
	t_vector	center;
	float		*positions;
	int			i;

	i = 0;
	center = model->bv.center;
	positions = model->vertex_table->positions;
	while (i < model->vertex_table->i_pos)
	{
		positions[i + 0] += 2 * center.x;
		positions[i + 1] += 2 * center.y;
		positions[i + 2] += 2 * center.z;
		i += 3;
	}
}

float	update_fade(int fade, float curr_fade, float delta)
{
	float speed;

	speed = 0.001f;
	if (fade && curr_fade < 1.0f)
		curr_fade += speed * delta;
	if (!fade && curr_fade > 0.0f)
		curr_fade -= speed * delta;
	return (curr_fade);
}

void	render(t_scop *scop)
{
	while (1)
	{
		draw_routine(scop);
		if (scop->rotate)
			scop->y_rotation += 0.2;
		adjust_view(&scop->camera.fps_mouse, &scop->camera, &scop->window);
		check_event(scop, &scop->window, &scop->camera);
		look_at_cont(&scop->camera, RH);
		build_rotation_matrix(scop->model.model, 0, scop->y_rotation, 0);
		scop->curr_fade = update_fade(scop->fade, scop->curr_fade,
										scop->camera.fps_mouse.time.delta);
		associate_standard_uniforms(&scop->gl, scop->model.model,
									scop->camera.view,
									scop->camera.projection);
		glUniformMatrix4fv(scop->gl.uniform_refs[OFFSET], 1, GL_TRUE,
							&scop->model.offset[0][0]);
		glUniform1f(scop->gl.uniform_refs[FADE], scop->curr_fade);
		glUniform1i(scop->gl.uniform_refs[RENDER_MODE], scop->render_mode);
		glUniform1f(scop->gl.uniform_refs[SHRINK_FACTOR], scop->shrink);
		glUniform1f(scop->gl.uniform_refs[EXPLODE_FACTOR],
			scop->explode_factor);
		glUniform1i(scop->gl.uniform_refs[INSTANCE_LEN], scop->instance_len);
		SDL_GL_SwapWindow(scop->window.window);
	}
}
