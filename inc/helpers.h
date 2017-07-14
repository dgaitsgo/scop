/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:52:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 14:42:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HELPERS_H
# define __HELPERS_H

void		*malloc_if(long size, int n);
void		free_if(void *ptr);
void		multi_free_4(void *addr1, void *addr2, void *addr3, void *addr4);
int			match_extension_to_enum(const char *file_extension);
char		*get_extension(const char *file_name);
char		*file_to_string(const char *path, const char *file);
int			count_char(char c, char *s);
void		set_to_zero3(int *a, int *b, int *c);
void		set_to_zero4(int *a, int *b, int *c, int *d);

#endif
