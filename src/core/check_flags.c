/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:19:14 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 11:57:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		check_flags(int flags)
{
	if (BIT_CHECK(flags, ONLY_GEOMETRY))
		ft_putstr("f %d %d %d %d\n");
	if (BIT_CHECK(flags, ALL_VERTS_DEFINED))
		ft_putstr("f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n");
	if (!BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		((BIT_CHECK(flags, NORMALS_DEFINED))))
		ft_putstr("f %d//%d %d//%d %d//%d %d//%d\n");
	if (BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		(!(BIT_CHECK(flags, NORMALS_DEFINED))))
		ft_putstr("f %d/%d %d/%d %d/%d %d/%d\n");
}

void		check_face_flags(char *line, int *flags)
{
	char	**tokens;
	char	*sub;

	tokens = ft_strsplit(line, ' ');
	if (count_char('/', tokens[1]) == 0)
	{
		BIT_SET(*flags, ONLY_GEOMETRY);
	}
	else
	{
		sub = strsep(&tokens[1], "/");
		if (sub[0] == '-')
			BIT_SET(*flags, NEGATIVE_INDEXES);
		sub = strsep(&tokens[1], "/");
		if (sub[0])
			BIT_SET(*flags, TEXT_COORDS_DEFINED);
		sub = strsep(&tokens[1], "/");
		if (sub[0] != '\0')
			BIT_SET(*flags, NORMALS_DEFINED);
		if (BIT_CHECK(*flags, TEXT_COORDS_DEFINED) &&
			BIT_CHECK(*flags, NORMALS_DEFINED))
			BIT_SET(*flags, ALL_VERTS_DEFINED);
	}
}
