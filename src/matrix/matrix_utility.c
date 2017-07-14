/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 00:04:22 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:32:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector	position_from_matrix(t_matrix m)
{
	return (new_vector(m[1][3], m[2][3], m[3][3]));
}

int			find_longest_axis(t_matrix m)
{
	float	big;

	big = largest(largest(m[0][0], m[1][1]), m[2][2]);
	if (big == m[0][0])
		return (X);
	else if (big == m[1][1])
		return (Y);
	else
		return (Z);
}
