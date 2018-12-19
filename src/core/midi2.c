/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 00:04:59 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 00:05:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_rest_of_message(t_midi_message *m)
{
	m->length_left_in_message = m->n_bytes - m->i_byte;
	m->length_to_copy = smallest(m->length_left_in_message, SYSEX_LENGTH);
	memcpy(
		m->sysex_message + m->sysex_length,
		m->packet->data, m->length_to_copy);
	m->sysex_length += m->length_to_copy;
	m->size = 0;
	m->i_byte = m->n_bytes;
	m->continue_sysex = (m->packet->data[m->n_bytes - 1] != 0xF7);
}

void	check_status(t_midi_message *m)
{
	m->size = 0;
	m->status = m->packet->data[m->i_byte];
	if (m->status < 0xC0)
		m->size = 3;
	else if (m->status < 0xE0)
		m->size = 2;
	else if (m->status < 0xF0)
		m->size = 3;
	else if (m->status == 0xF0)
		get_rest_of_message(m);
	else if (m->status < 0xF3)
		m->size = 3;
	else if (m->status == 0xF3)
		m->size = 2;
	else
		m->size = 1;
}
