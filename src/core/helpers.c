/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:49:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 04:53:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			count_char(char c, char *s)
{
	int		i;
	int		n;
	
	n = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			n++;
		i++;
	}
	return (n);
}

void		multi_free_4(void *addr1, void *addr2,
			void *addr3, void *addr4)
{
	free_if(addr1);
	free_if(addr2);
	free_if(addr3);
	free_if(addr4);
}

void		set_to_zero4(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void		set_to_zero3(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

void		*malloc_if(long size, int n)
{
	void	*mem;

	//total_bytes += size * n;	
	mem = malloc(size * n);
	if (mem != NULL)
		return (mem);
	printf("Memory erro");
	exit (1);
	return (NULL);
}

void		free_if(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
