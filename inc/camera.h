/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:00:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:53:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "matrix.h"
# include "time.h"

enum				e_handedness
{
	LH,
	RH,
};

typedef	struct		s_fps_mouse
{
	t_vector		position;
	t_time			time;
	float			horizontal_angle;
	float			vertical_angle;
	float			speed;
	float			mouse_speed;
	int				xpos;
	int				ypos;
}					t_fps_mouse;

typedef struct		s_camera
{
	t_fps_mouse		fps_mouse;
	t_matrix		view;
	t_matrix		projection;
	t_matrix		inverse_view_matrix;
	t_vector		position;
	t_vector		direction;
	t_vector		eye;
	t_vector		up;
	t_vector		forward;
	t_vector		right;
	double			half_width;
	double			half_height;
	double			pixel_width;
	double			pixel_height;
}					t_camera;

void				look_at_lh(t_matrix m,
							t_vector eye,
							t_vector center,
							t_vector up);

void				look_at_rh(t_matrix m,
							t_vector eye,
							t_vector center,
							t_vector up);

void				perspective_matrix(
							t_matrix m,
							float fov,
							float aspect_ratio);

void				init_camera(t_camera *camera);

void				init_fps_mouse(t_fps_mouse *m);

void				calc_viewing_angles(
							t_fps_mouse *m,
							float delta,
							float width,
							float height);

void				set_camera(
						t_camera *c,
						t_vector position,
						t_vector direction,
						t_vector up);

void				calc_camera_rig(t_camera *c, t_fps_mouse *m);

void				look_at_cont(t_camera *c, int handedness);
void				set_camera(
						t_camera *c,
						t_vector position,
						t_vector direction,
						t_vector up);

#endif
