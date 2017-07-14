/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:43:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 01:12:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"scop.h"

void		init_transform(t_transform *t)
{
	t->scale = new_point(1, 1, 1, 1);
	t->rotation = new_vector(0, 0, 0);
	t->translation = new_vector(0, 0, 0);
}
