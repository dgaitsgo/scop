/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:50:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 11:55:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		init_gl_texture_list(t_gl *gl)
{
	gl->root_texture = new_texture();
	gl->curr_texture = gl->root_texture;
}

void		load_textures(t_gl *gl)
{
	init_gl_texture_list(gl);
	get_textures_from_directory(gl->curr_texture);
	gen_and_activate_texture(gl->root_texture);
	set_texture(gl);
}
