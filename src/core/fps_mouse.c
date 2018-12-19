/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 06:04:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 22:51:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			init_fps_mouse(t_fps_mouse *m)
{
	m->position = new_vector(0, 0, 0);
	m->horizontal_angle = 3.14f;
	m->vertical_angle = 0.0f;
	m->speed = 0.02f;
	m->mouse_speed = 0.0005f;
}

void			reset_mouse(t_window *window)
{
	SDL_WarpMouseInWindow(
		window->window,
		window->width / 2,
		window->height / 2);
}

void			calc_viewing_angles(t_fps_mouse *m,
									float delta,
									float width,
									float height)
{
	m->horizontal_angle += m->mouse_speed * (width / 2 - m->xpos);
	m->vertical_angle += m->mouse_speed * (height / 2 - m->ypos);
}

void			adjust_view(t_fps_mouse *m,
							t_camera *c,
							t_window *window)
{
	m->time.curr_time = SDL_GetTicks();
	m->time.delta = m->time.curr_time - m->time.last_time;
	SDL_GetMouseState(&m->xpos, &m->ypos);
	reset_mouse(window);
	calc_viewing_angles(m, m->time.delta, (float)SDL_WIDTH, (float)SDL_HEIGHT);
	calc_camera_rig(c, m);
	m->time.last_time = m->time.curr_time;
}
