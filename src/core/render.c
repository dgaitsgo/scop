/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 20:35:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_texture(t_gl *gl)
{
	int tex_loc;

	tex_loc = glGetUniformLocation (gl->shdr_program, "basic_texture");
	glUseProgram(gl->shdr_program);
	glUniform1i(tex_loc, 0);
}

void	draw_routine(t_scop *scop)
{
	int			i;
	t_vector	sky;

	i = 0;
//	set_vector(&sky, 255, 255, 255);
	set_vector(&sky, 19, 12, 30);
	clear_open_gl(sky, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	set_texture(&scop->gl);
	glUseProgram(scop->gl.shdr_program);
	glBindVertexArray(scop->gl.vao);
	glDrawArraysInstanced(	GL_TRIANGLES,
					0,
					scop->model.vertex_table->i_pos / 3,
					scop->instance_len * scop->instance_len);
		i++;
}

void	polygon_mode(int pm)
{
	if (pm == 1)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void	check_event(t_scop *scop, t_window *window, t_camera *c)
{
	float 		delta_time;
	t_fps_mouse *m;

	m = &c->fps_mouse;
	delta_time = m->time.delta;
	while (SDL_PollEvent(&SDL_EVENT))
	{
		if (SDL_EVENT.type == SDL_QUIT || KEY == SDLK_ESCAPE)
			kill_sdl(window);
		if (KEY == SDLK_w)
			c->position = 
				vector_add(c->position,
				vector_scale(c->direction, delta_time * m->speed));
		if (KEY == SDLK_s)
			c->position =
				vector_subtract(c->position,
				vector_scale(c->direction, delta_time * m->speed));
		if (KEY == SDLK_d)
			c->position =
				vector_add(c->position,
				vector_scale(c->right, delta_time * m->speed));
		if (KEY == SDLK_a)
			c->position =
				vector_subtract(c->position,
				vector_scale(c->right, delta_time * m->speed));
		if (KEY == SDLK_b)
			scop->shrink = largest(0, scop->shrink - delta_time * 0.0005);
		if (KEY == SDLK_n)
			scop->shrink = smallest(1, scop->shrink + delta_time * 0.0005);
		if (KEY == SDLK_j)
			scop->explode_factor = largest(0, scop->explode_factor - delta_time * 0.001);
		if (KEY == SDLK_k)
			scop->explode_factor += delta_time * 0.001;
		if (window->event.type == SDL_KEYDOWN && window->event.key.repeat == 0)
		{
			if (KEY == SDLK_o)
				scop->instance_len = smallest(scop->instance_len + 1, 4);
			if (KEY == SDLK_i)
				scop->instance_len = largest(scop->instance_len - 1, 1);
			if (KEY == SDLK_f)
			{
				scop->polygon_mode += scop->polygon_mode == MAX_POLYGON_MODES ? -MAX_POLYGON_MODES : 1;
				polygon_mode(scop->polygon_mode);
				init_open_gl(scop);
				render(scop);
			}
			if (KEY == SDLK_c)
				scop->fade = !scop->fade;	
			if (KEY == SDLK_m)
				scop->render_mode +=
					scop->render_mode == MAX_RENDER_MODES ? -MAX_RENDER_MODES : 1 ;
			}
	}
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
	int i;

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
	{
		curr_fade += speed * delta;
		//curr_fade = smallest(curr_fade, 1.0);
	}
	if (!fade && curr_fade > 0.0f)
	{
		curr_fade -= speed * delta;
		//curr_fade = largest(curr_fade, 0);
	}
	return (curr_fade);
}

void	render(t_scop *scop)
{
	while (1)
	{
		draw_routine(scop);
		if (scop->rotate) {
			scop->y_rotation += 0.2;
		}
		adjust_view(&scop->camera.fps_mouse, &scop->camera, &scop->window);
		check_event(scop, &scop->window, &scop->camera);
		look_at_cont(&scop->camera, RH);
		build_rotation_matrix(scop->model.model, 0, scop->y_rotation, 0);
		//build_transformation_matrix(scop->model.model, t);
		scop->curr_fade = update_fade(scop->fade, scop->curr_fade, scop->camera.fps_mouse.time.delta);
		associate_standard_uniforms(&scop->gl,
									scop->model.model,
									scop->camera.view,
									scop->camera.projection);
		glUniformMatrix4fv(	scop->gl.uniform_refs[OFFSET],
							1, GL_TRUE,
							&scop->model.offset[0][0]);
		glUniform1f(scop->gl.uniform_refs[FADE], scop->curr_fade);
		glUniform1i(scop->gl.uniform_refs[RENDER_MODE], scop->render_mode);
		glUniform1f(scop->gl.uniform_refs[SHRINK_FACTOR], scop->shrink);
		glUniform1f(scop->gl.uniform_refs[EXPLODE_FACTOR], scop->explode_factor);
		glUniform1i(scop->gl.uniform_refs[INSTANCE_LEN], scop->instance_len);
		SDL_GL_SwapWindow(scop->window.window);
	}
}

