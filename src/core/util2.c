/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:57:50 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 23:06:16 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	multi_free_4(
			void *addr1,
			void *addr2,
			void *addr3,
			void *addr4)
{
	free_if(addr1);
	free_if(addr2);
	free_if(addr3);
	free_if(addr4);
}

void	set_to_zero4(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	set_to_zero3(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

void	*malloc_if(long size, int n)
{
	void	*mem;

	mem = malloc(size * n);
	if (mem != NULL)
		return (mem);
	printf("Memory error");
	exit(1);
	return (NULL);
}

void	free_if(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
