/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 23:04:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:53:31 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	projection_matrix(t_matrix m, float fov, float aspect_ratio)
{
	float range;
	float sx;
	float sy;
	float sz;
	float pz;

	range = tan(in_radians(fov * 0.5)) * Z_NEAR;
	sx = (2 * Z_NEAR) / (range * aspect_ratio + range * aspect_ratio);
	sy = Z_NEAR / range;
	sz = -(Z_FAR + Z_NEAR) / (Z_FAR - Z_NEAR);
	pz = -(2 * Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR);
	zero_matrix(m);
	m[0][0] = sx;
	m[1][1] = sy;
	m[2][2] = sz;
	m[2][3] = -1;
	m[3][2] = pz;
}

void	calc_camera_rig(t_camera *c, t_fps_mouse *m)
{
	c->direction = new_vector(
						cos(m->vertical_angle) * sin(m->horizontal_angle),
						sin(m->vertical_angle),
						cos(m->vertical_angle) * cos(m->horizontal_angle));
	c->right = new_vector(
						sin(m->horizontal_angle - 3.14f / 2.0f),
						0,
						cos(m->horizontal_angle - 3.14f / 2.0f));
	c->up = vector_cross(c->right, c->direction);
}

void	set_camera(
					t_camera *c,
					t_vector position,
					t_vector direction,
					t_vector up)
{
	c->position = position;
	c->direction = direction;
	c->up = up;
}

void	init_camera(t_camera *camera)
{
	init_fps_mouse(&camera->fps_mouse);
	projection_matrix(camera->projection, FOV, ASPECT_RATIO);
	set_vector(&camera->forward, 0, 0, 1);
	set_vector(&camera->up, 0, 1, 0);
}
