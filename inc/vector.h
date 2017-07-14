/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:14 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 22:19:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H
# define __VECTOR_H
# include "matrix.h"

typedef struct		s_vector2
{
	float			x;
	float			y;
}					t_vector2;

typedef struct		s_vector3
{
	float			x;
	float			y;
	float			z;
}					t_vector3;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vector;

typedef struct
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color_vector;

t_vector			vector_add_3(t_vector a, t_vector b, t_vector c);
t_vector			vector_add_4(t_vector a, t_vector b,
						t_vector c, t_vector d);
t_vector			vector_max(t_vector a, t_vector b);
t_vector			vector_min(t_vector a, t_vector b);
t_vector			get_right_vector(t_matrix m);
t_vector			get_up_vector(t_matrix m);
t_vector			get_backward_vector(t_matrix m);
t_vector			get_translation_vector(t_matrix m);
t_vector			get_scale_vector(t_matrix m);
t_vector			new_point(float x, float y, float z, float w);
t_vector			new_vector(float a, float b, float c);
void				copy_vector(t_vector *dst, t_vector *src);
void				set_vector(t_vector *a, float x, float y, float z);
int					compare_vector(t_vector a, t_vector b);
t_vector			vector_pow(t_vector a, float n);
t_vector			vector_inverse(t_vector a);
t_vector			vector_const_divide(t_vector a, float b);
t_vector			vector_divide(t_vector a, t_vector b);
t_vector			*new_vector_ptr(float x, float y, float z);
t_vector			vector_cross(t_vector a, t_vector b);
t_vector			vector_scale(t_vector a, float c);
t_vector			vector_inverse_scale(t_vector a, float c);
t_vector			vector_add(t_vector a, t_vector b);
t_vector			vector_const_add(t_vector a, float b);
t_vector			vector_subtract(t_vector a, t_vector b);
t_vector			vector_multiply(t_vector a, t_vector b);
t_vector			unit_vector(t_vector a);
float				vector_length(t_vector a);
int					compare_vector(t_vector a, t_vector b);
float				dot_product(t_vector a, t_vector b);
t_vector			matrix_transform_point(t_vector *pnt, t_matrix m);
t_vector			matrix_transform_raster_point(t_vector *pnt, t_matrix m);
t_vector			matrix_transform_direction(t_vector *dir, t_matrix m);
t_vector			matrix_transform_normal(t_vector *normal, t_matrix m);
void				rgb_to_normal(t_vector *color);

#endif
