/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:14:06 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 17:46:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MIDI_H
# define __MIDI_H

# include <CoreMIDI/MIDIServices.h>
# include <CoreMIDI/MIDISetup.h>
# include <CoreMIDI/MIDIThruConnection.h>
# include <CoreMIDI/MIDIDriver.h>

# define UNIQUE_ID		468733292
# define SYSEX_LENGTH	1024

typedef struct			s_midi_message
{
	int					continue_sysex;
	UInt16				n_bytes;
	UInt16				i_byte;
	UInt16				size;
	const MIDIPacket	*packet;
	int					button;
	int					data;
	unsigned char		sysex_message[SYSEX_LENGTH];
	unsigned int		sysex_length;
	unsigned char		status;
	unsigned int		length_left_in_message;
	unsigned int		length_to_copy;
	unsigned char		message_type;
	unsigned char		message_channel;
}						t_midi_message;

#endif
