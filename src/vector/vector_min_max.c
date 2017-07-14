/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/04/23 22:27:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector	vector_max(t_vector a, t_vector b)
{
	t_vector	max;

	max.x = largest(a.x, b.x);
	max.y = largest(a.y, b.y);
	max.z = largest(a.z, b.z);
	max.w = largest(a.w, b.w);
	return (max);
}

t_vector	vector_min(t_vector a, t_vector b)
{
	t_vector	min;

	min.x = smallest(a.x, b.x);
	min.y = smallest(a.y, b.y);
	min.z = smallest(a.z, b.z);
	min.w = smallest(a.w, b.w);
	return (min);
}
