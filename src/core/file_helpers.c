/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:36:57 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 17:14:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
	match extension to enum:

	TO DO;
	Should be more general to accept an array of strings and expected values
	
	problems:
	this would match ".geomXXX"
*/

int	match_extension_to_enum(const char *file_extension)
{
	if (file_extension != NULL)
	{
		if (ft_strncmp(file_extension, ".frag", 4) == 0)
			return (GL_FRAGMENT_SHADER);
		if (ft_strncmp(file_extension, ".geom", 4) == 0)
			return (GL_GEOMETRY_SHADER);
		if (ft_strncmp(file_extension, ".vert", 4) == 0)
			return (GL_VERTEX_SHADER);
		if (ft_strncmp(file_extension, ".tga", 4) == 0)
			return (TGA);
	}
	return (INVALID);
}

char		*get_extension(const char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.');
	return (extension);
}

char	*file_to_string(const char *path, const char *file)
{
	FILE	*fd;
	long	size;
	char	buff[512];
	char	*dst;

	if (path != NULL)
		sprintf(buff, "%s%s", path, file);
	else
		sprintf(buff, "%s", file);
	if (!(fd = fopen(buff, "r")))
		exit(1);
	fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	dst = malloc(size);
	if (dst)
	{
		fread(dst, 1, size + 1, fd);
		dst[size] = '\0';
	}
	fclose(fd);
	return (dst);
}
