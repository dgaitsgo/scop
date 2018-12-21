/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:36:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:56:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEXTURE_H
# define __TEXTURE_H

# define TEXTURE_PATH			"./textures/"
# define MAX_TEXTURES			8

# include "open_gl.h"

enum						e_texture_types
{
	TGA,
};

typedef struct				s_texture_lst
{
	GLuint					ref;
	int						file_type;
	unsigned char			image_type;
	unsigned char			bit_depth;
	short int				width;
	short int				height;
	long					image_size;
	int						color_mode;
	unsigned char			*data;
	struct s_texture_lst	*next;
	struct s_texture_lst	*previous;
}							t_texture_lst;

void						parse_tga(const char *file_name, t_texture_lst *t);

#endif
