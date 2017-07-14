/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:17:55 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/29 01:23:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		about_tga(t_texture_lst *t, FILE *f)
{
	unsigned char	trash_char;
	short int		trash_int;

	printf("\nAbout Texture :\n");
	//first two bytes are id length, useless
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);

	fread(&t->image_type, sizeof(unsigned char), 1, f);
	if (t->image_type != 2 && t->image_type != 3)
		exit (1);
	if (t->image_type == 2)
		printf("Uncompressed RGB Image\n");
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);

	fread(&t->width, sizeof(short int), 1, f);
	fread(&t->height, sizeof(short int), 1, f);
	printf("Width == %d\n", t->width);	
	printf("Height == %d\n", t->height);	

	fread(&t->bit_depth, sizeof(unsigned char), 1, f);
	t->color_mode = t->bit_depth / 8;

	printf("Color mode == %d\n", t->color_mode);	

	fread(&trash_char, sizeof(unsigned char), 1, f);
	t->image_size = t->width * t->height * t->color_mode;
}

void bgr_to_rgb(unsigned char *data, int size)
{
	int				i;
	char			temp;

	i = 0;
	while (i < size)
	{
		temp = data[i + 0];
		data[i + 0] = data[i + 2];
		data[i + 2] = temp;
		i += 3;
	}
}

void	parse_tga(const char *file_name, t_texture_lst *t)
{
	FILE			*f;
	char			buff[512];

	sprintf(buff, "%s%s", TEXTURE_PATH, file_name);
	f = fopen(buff, "r");
	assert(f != NULL);
	about_tga(t, f);
	t->data = ft_memalloc(sizeof(unsigned char) * t->image_size);
	if (fread(t->data, 1, t->image_size, f) != t->image_size)
		//ft_error (UNEXPECTED_EOF)
		exit (-1);
	bgr_to_rgb(t->data, t->image_size);
}
