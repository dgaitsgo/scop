/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:48:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:35:50 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TRANSFORM_H
# define __TRANSFORM_H

#include "matrix.h"

typedef struct	s_transform
{
	t_vector	scale;
	t_vector	rotation;
	t_vector	translation;
}				t_transform;

void			init_transform(t_transform *t);
void			build_normal_to_world(t_matrix norm_to_world, t_transform t);
void			default_transformation(t_transform *transformation);

void			rotate_x(t_matrix rx, float x);
void			rotate_y(t_matrix ry, float y);
void			rotate_z(t_matrix rz, float z);
void			build_rotation_matrix(t_matrix rotation,
				float x, float y, float z);

void			build_scale_matrix(t_matrix m, float x, float y, float z);
void			build_translation_matrix(t_matrix m,
				float x, float y, float z);
void			build_inverse_rotation_matrix(t_matrix inverse_rotation,
				float x, float y, float z);
void			build_transformation_matrix(t_matrix transform, t_transform t);
#endif
