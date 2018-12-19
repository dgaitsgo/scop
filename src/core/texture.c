/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:40:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 11:52:16 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_texture_lst	*new_texture(void)
{
	t_texture_lst	*t;

	t = ft_memalloc(sizeof(t_texture_lst));
	t->next = NULL;
	t->previous = NULL;
	t->data = NULL;
	return (t);
}

void			set_open_gl_texture_flags(void)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

void			next_texture(t_texture_lst *e)
{
	e->previous = e;
	e->next = new_texture();
	e = e->next;
}

void			gen_and_activate_texture(t_texture_lst *t)
{
	glGenTextures(1, &t->ref);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, t->ref);
	glGenerateMipmap(GL_TEXTURE_2D);
	set_open_gl_texture_flags();
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGB,
		t->width,
		t->height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		t->data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void			get_textures_from_directory(t_texture_lst *texture)
{
	DIR				*dir;
	struct dirent	*file;
	char			*ext_str;
	int				ext;

	if (!(dir = opendir(TEXTURE_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext_str = get_extension(file->d_name);
		ext = match_extension_to_enum(ext_str);
		if (ext != INVALID)
		{
			if (ext == TGA)
				parse_tga(file->d_name, texture);
			next_texture(texture);
		}
	}
}
