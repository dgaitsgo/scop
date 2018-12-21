/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:02:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:50:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	move_camera(t_window *window, t_camera *c, float time)
{
	if (KEY == SDLK_w)
		c->position =
			vector_add(c->position,
			vector_scale(c->direction, time));
	if (KEY == SDLK_s)
		c->position =
			vector_subtract(c->position,
			vector_scale(c->direction, time));
	if (KEY == SDLK_d)
		c->position =
			vector_add(c->position,
			vector_scale(c->right, time));
	if (KEY == SDLK_a)
		c->position =
			vector_subtract(c->position,
			vector_scale(c->right, time));
}

void	shader_control(t_window *window, t_scop *scop, float delta_time)
{
	if (KEY == SDLK_b)
		scop->shrink = largest(0, scop->shrink - delta_time * 0.0005);
	else if (KEY == SDLK_n)
		scop->shrink = smallest(1, scop->shrink + delta_time * 0.0005);
	else if (KEY == SDLK_j)
		scop->explode_factor =
			largest(0, scop->explode_factor - delta_time * 0.001);
	else if (KEY == SDLK_k)
		scop->explode_factor += delta_time * 0.001;
}

void	render_mode(t_window *window, t_scop *scop)
{
	if (KEY == SDLK_o)
		scop->instance_len = smallest(scop->instance_len + 1, 4);
	else if (KEY == SDLK_i)
		scop->instance_len = largest(scop->instance_len - 1, 1);
	else if (KEY == SDLK_f)
	{
		scop->polygon_mode +=
			scop->polygon_mode == MAX_POLYGON_MODES ? -MAX_POLYGON_MODES : 1;
		polygon_mode(scop->polygon_mode);
		init_open_gl(scop);
		render(scop);
	}
	else if (KEY == SDLK_c)
		scop->fade = !scop->fade;
	else if (KEY == SDLK_m)
		scop->render_mode +=
			scop->render_mode == MAX_RENDER_MODES ? -MAX_RENDER_MODES : 1;
}

void	check_event(t_scop *scop, t_window *window, t_camera *c)
{
	float		delta_time;
	t_fps_mouse	*m;

	m = &c->fps_mouse;
	delta_time = m->time.delta;
	while (SDL_PollEvent(&SDL_EVENT))
	{
		if (SDL_EVENT.type == SDL_QUIT || KEY == SDLK_ESCAPE)
			kill_sdl(window);
		else if (KEY == SDLK_w || KEY == SDLK_s ||
			KEY == SDLK_d || KEY == SDLK_a)
			move_camera(window, c, delta_time * m->speed);
		else if (KEY == SDLK_b || KEY == SDLK_n ||
			KEY == SDLK_j || KEY == SDLK_k)
			shader_control(window, scop, delta_time);
		else if (window->event.type == SDL_KEYDOWN &&
			window->event.key.repeat == 0)
			render_mode(window, scop);
	}
}
