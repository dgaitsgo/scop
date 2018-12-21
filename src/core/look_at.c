/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:51:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:53:21 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	look_at_lh(
		t_matrix m,
		t_vector eye,
		t_vector center,
		t_vector up)
{
	t_vector	f;
	t_vector	s;
	t_vector	u;

	zero_matrix(m);
	f = unit_vector(vector_subtract(center, eye));
	s = unit_vector(vector_cross(up, f));
	u = vector_cross(f, s);
	m[0][0] = s.x;
	m[0][1] = u.x;
	m[0][2] = f.x;
	m[0][3] = -dot_product(s, eye);
	m[1][0] = s.y;
	m[1][1] = u.y;
	m[1][2] = f.y;
	m[1][3] = -dot_product(u, eye);
	m[2][0] = s.z;
	m[2][1] = u.z;
	m[2][2] = f.z;
	m[2][3] = -dot_product(f, eye);
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void	look_at_rh(
		t_matrix m,
		t_vector eye,
		t_vector center,
		t_vector up)
{
	t_vector	f;
	t_vector	s;
	t_vector	u;

	zero_matrix(m);
	f = unit_vector(vector_subtract(center, eye));
	s = unit_vector(vector_cross(f, up));
	u = vector_cross(s, f);
	m[0][0] = s.x;
	m[0][1] = u.x;
	m[0][2] = -f.x;
	m[0][3] = -dot_product(s, eye);
	m[1][0] = s.y;
	m[1][1] = u.y;
	m[1][2] = -f.y;
	m[1][3] = -dot_product(u, eye);
	m[2][0] = s.z;
	m[2][1] = u.z;
	m[2][2] = -f.z;
	m[2][3] = dot_product(f, eye);
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
