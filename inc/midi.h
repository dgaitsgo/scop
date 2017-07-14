#ifndef __MIDI_H
# define __MIDI_H

#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIServices.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDISetup.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIThruConnection.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIDriver.h"
//#include <Foundation/NSObjCRuntime.h>
//#include <Foundation/NSDictionary.h>

//TraktorX11
#define UNIQUE_ID		468733292
#define SYSEX_LENGTH	1024

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
