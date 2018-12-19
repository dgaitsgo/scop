/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:53:34 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 22:59:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		push(float *array, int *pos, float item)
{
	(*pos)++;
	array[*pos] = item;
}

int			round_up(int num, int factor)
{
	return (num + factor - 1 - (num - 1) % factor);
}

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
