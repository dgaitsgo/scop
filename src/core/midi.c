/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:46:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 00:06:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	copy_sysex_message(t_midi_message *m)
{
	m->length_to_copy = smallest(m->n_bytes, SYSEX_LENGTH - m->sysex_length);
	memcpy(
		m->sysex_message + m->sysex_length,
		m->packet->data,
		m->length_to_copy);
	m->sysex_length += m->length_to_copy;
	m->continue_sysex = (m->packet->data[m->n_bytes - 1] == 0xF7);
}

void	midi_state_change(int button, int value, t_scop *scop)
{
	if (button == 0)
		scop->explode_factor = map(value, new_range(0, 127, 0, 1));
	else if (button == 2)
		scop->shrink = map(value, new_range(0, 127, 0, 1));
	else if (button == 4)
		scop->instance_len = largest(1, map(value, new_range(0, 127, 0, 4)));
	else if (button == 8 && value == 127)
		scop->render_mode +=
			scop->render_mode == MAX_RENDER_MODES ? -MAX_RENDER_MODES : 1;
	else if (button == 10 && value == 127)
		scop->fade = !scop->fade;
	else if (button == 18 && value == 127)
		scop->rotate = !scop->rotate;
	else if (button == 16 && value == 127)
		scop->y_rotation += 10;
	else if (button == 16 && value == 1)
		scop->y_rotation -= 10;
	else if (button == 17 && value == 1)
	{
		polygon_mode(scop->polygon_mode);
		init_open_gl(scop);
		render(scop);
	}
}

void	midi_input_callback(
			const MIDIPacketList *list,
			void *proc_ref,
			void *src_ref)
{
	t_midi_message	m;
	int				i;

	i = 0;
	m.continue_sysex = 0;
	m.sysex_length = 0;
	m.packet = &list->packet[0];
	while (i < list->numPackets)
	{
		m.n_bytes = m.packet->length;
		if (m.continue_sysex)
			copy_sysex_message(&m);
		if (!m.continue_sysex || m.sysex_length == SYSEX_LENGTH)
			m.sysex_length = 0;
		m.i_byte = 0;
		while (m.i_byte < m.n_bytes)
		{
			check_status(&m);
			midi_state_change(m.packet->data[m.i_byte + 1],
				m.packet->data[m.i_byte + 2], (t_scop *)proc_ref);
			m.i_byte += m.size;
		}
		i++;
		m.packet = MIDIPacketNext(m.packet);
	}
}

int		connect_devices(MIDIPortRef input_port)
{
	int				n_devices;
	int				i;
	int				at_least_one;
	MIDIEndpointRef src;
	OSStatus		result;

	i = 0;
	at_least_one = 0;
	n_devices = MIDIGetNumberOfDevices();
	while (i < n_devices)
	{
		src = MIDIGetSource(i);
		result = MIDIPortConnectSource(input_port, src, NULL);
		if (result == noErr)
			at_least_one = 1;
		i++;
	}
	return (at_least_one);
}

int		init_midi(t_scop *scop)
{
	MIDIClientRef	midi_client;
	MIDIPortRef		input_port;
	MIDIEndpointRef	end_point;
	MIDIObjectType	found_obj;
	OSStatus		result;

	result = MIDIClientCreate(CFSTR("MIDI client"), NULL, NULL, &midi_client);
	if (result != noErr)
		return (0);
	result = MIDIDestinationCreate(midi_client,
		CFSTR("Virtual port"), midi_input_callback, NULL, &end_point);
	if (result != noErr)
		return (0);
	result = MIDIInputPortCreate(midi_client,
		CFSTR("Input port"), midi_input_callback, scop, &input_port);
	if (result != noErr)
		return (0);
	if (connect_devices(input_port))
	{
		CFRunLoopRun();
		return (1);
	}
	return (0);
}
