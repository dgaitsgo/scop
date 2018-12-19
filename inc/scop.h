/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:40:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/19 13:41:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOP_H
# define __SCOP_H

#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIServices.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDISetup.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIThruConnection.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIDriver.h"
#include "/System/Library/Frameworks/CoreFoundation.framework/Versions/A/Headers/CFString.h"

#include <stdio.h>
#include <dirent.h>
#include <assert.h>
#include <float.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include "window.h"
#include "open_gl.h"
#include "camera.h"
#include "window.h"
#include "macros.h"
#include "model.h"
#include "flags.h"
#include "helpers.h"
#include "texture.h"
#include "transform.h"
#include "libft.h"
#include "ft_math.h"
#include "parse_mesh.h"
#include "midi.h"
#include "triangle_idx.h"

enum				e_3d_types
{
	OBJ,
};

typedef struct		s_scop
{
	WINDOW			window;
	t_model			model;
	t_gl			gl;
	t_camera		camera;
	float			shrink;
	float			explode_factor;
	float			curr_fade;
	float			y_rotation;
	int				rotate;
	int				polygon_mode;
	int				fade;
	int				render_mode;
	int				instance_len;
}					t_scop;

void				init_open_gl(t_scop *scop);
void				order_data(	t_vertex_table *v,
								t_obj_data **data,
								int n_groups,
								int flags);
void				polygon_mode(int pm);
void				check_groups(t_group_lst *group);
t_vertex_table		*fetch_vertex_table_mem(t_obj_data **data,
											int n_groups,
											int flags);
t_obj_data			**fetch_obj_data_mem(t_group_lst *group, int n_groups);
void				push_face(t_obj_data *data, char *line, int flags);
void				fill_model_arrays(t_model *model);
t_gl				*init_gl_mem(void);
void				init_array_memory(t_model *m);
void				status_gl(const char *message, int line, char *file);
void				load_obj(t_model *model, FILE *fd);
void				poll_events(t_window *window, t_transform *t);
void				render(t_scop *scop);
void				adjust_view(t_fps_mouse *m,
								t_camera *c,
								t_window *window);
void				load_textures(t_gl *gl);
int					init_midi(t_scop *scop);
void				push(float *array, int *pos, float item);
int					round_up(int num, int factor);
void				check_status(t_midi_message *m);
void				set_texture(t_gl *gl);
void				draw_routine(t_scop *scop);
t_shader_lst		*get_curr_shader(t_gl *gl, int shader_type);
void				generate_vbo(GLuint *ref, int n_faces, GLfloat *vertices);
void				generate_vao(GLuint *ref);
t_texture_lst		*new_texture(void);
void				set_open_gl_texture_flags(void);
void				next_texture(t_texture_lst *e);
void				gen_and_activate_texture(t_texture_lst *t);
void				get_textures_from_directory(t_texture_lst *texture);
void				check_event(t_scop *scop, t_window *window, t_camera *c);
void				check_flags(int flags);
void				check_face_flags(char *line, int *flags);
void				push_vertex(t_obj_data *data, char *line);
void				push_text_coord(t_obj_data *data, char *line);
void				push_normal(t_obj_data *data, char *line);
void				bind_shader(GLuint program,
						GLuint vert_ref,
						GLuint geom_ref,
						GLuint frag_ref);
void				count_group_data(FILE *fd, t_group_lst *group,
					int *n_groups, int *flags);
#endif
