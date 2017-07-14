/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 00:04:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:30:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		rotate_x(t_matrix rx, float x)
{
	rx[0][0] = 1;
	rx[0][1] = 0;
	rx[0][2] = 0;
	rx[0][3] = 0;
	rx[1][0] = 0;
	rx[1][1] = (float)cos(x);
	rx[1][2] = -(float)sin(x);
	rx[1][3] = 0;
	rx[2][0] = 0;
	rx[2][1] = (float)sin(x);
	rx[2][2] = (float)cos(x);
	rx[2][3] = 0;
	rx[3][0] = 0;
	rx[3][1] = 0;
	rx[3][2] = 0;
	rx[3][3] = 1;
}

void		rotate_y(t_matrix ry, float y)
{
	ry[0][0] = (float)cos(y);
	ry[0][1] = 0;
	ry[0][2] = (float)sin(y);
	ry[0][3] = 0;
	ry[1][0] = 0;
	ry[1][1] = 1;
	ry[1][2] = 0;
	ry[1][3] = 0;
	ry[2][0] = -(float)sin(y);
	ry[2][1] = 0;
	ry[2][2] = (float)cos(y);
	ry[2][3] = 0;
	ry[3][0] = 0;
	ry[3][1] = 0;
	ry[3][2] = 0;
	ry[3][3] = 1;
}

void		rotate_z(t_matrix rz, float z)
{
	rz[0][0] = (float)cos(z);
	rz[0][1] = -(float)sin(z);
	rz[0][2] = 0;
	rz[0][3] = 0;
	rz[1][0] = (float)sin(z);
	rz[1][1] = (float)cos(z);
	rz[1][2] = 0;
	rz[1][3] = 0;
	rz[2][0] = 0;
	rz[2][1] = 0;
	rz[2][2] = 1;
	rz[2][3] = 0;
	rz[3][0] = 0;
	rz[3][1] = 0;
	rz[3][2] = 0;
	rz[3][3] = 1;
}

void		build_rotation_matrix(t_matrix rotation,
float x, float y, float z)
{
	t_matrix	rx;
	t_matrix	ry;
	t_matrix	rz;
	t_matrix	res;

	rotate_x(rx, in_radians(x));
	rotate_y(ry, in_radians(y));
	rotate_z(rz, in_radians(z));
	matrix_multiply(res, ry, rx);
	matrix_multiply(rotation, rz, res);
}
