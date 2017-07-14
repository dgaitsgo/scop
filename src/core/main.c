/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 17:17:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

FILE		*scop_log;

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

/*
	1. Documentation
	2. Defensive coding
		a. custom assert
			i. for error handling
			ii. for abotss
		b. persistence check
	3. Error handling
		c. logs : log(char *message, &adress, __FILE__, __LINE__);
		I should be able to look at an error and
			Know where it happened
			What was the value, but how to keep types?
*/

void	center_model_in_view(t_camera *c, t_model *m)
{
	t_vector pos;
	t_vector direction;

	pos = new_vector(	m->bv.center.x,
						m->bv.center.y,
						m->bv.center.z + m->bv.diameter);
	direction = new_vector(0, 0, -1);
	set_camera(c, pos, direction, new_vector(0, 1, 0));
	look_at_cont(c, LH);
}

void	setup_render(t_scop *scop)
{
	build_translation_matrix(scop->model.offset,
	-scop->model.bv.center.x,
	-scop->model.bv.center.y,
	-scop->model.bv.center.z);

	// Wrap this up in a propper "setup"
	// then call mainloop - putimage makes a nice container
	set_standard_shader_uniforms(&scop->gl);
	scop->camera.fps_mouse.time.last_time = SDL_GetTicks();
	center_model_in_view(&scop->camera, &scop->model);
	reset_mouse(&scop->window);
	scop->rotate = 1;
	scop->y_rotation = 0;
	scop->fade = 0;
	scop->shrink = 1.0f;
	scop->explode_factor = 0.0f;
	scop->curr_fade = 0.0f;
	scop->render_mode = 0;
	scop->instance_len = 1;
	printf("MODEL DIAMETER : %f\n", scop->model.bv.diameter);
	glUniform1f(scop->gl.uniform_refs[MODEL_RADIUS], scop->model.bv.diameter / 2);
}

int			main(int argc, char **argv)
{
	t_scop	scop;
	FILE	*fd;

	scop.polygon_mode = 0;
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		assert(fd != NULL);
		
		//this should have getters, window size can change in execution
		init_window(&scop.window, argv[1], (int)WIN_WIDTH, (int)WIN_HEIGHT);	
		printf("Loaded window\n");
		//gl struct should be initited also
		init_model(&scop.model);
		printf("Initialized model\n");
		init_camera(&scop.camera);
		printf("Initialized camera\n");
		load_obj(&scop.model, fd);
		printf("Loaded obj\n");
		load_shaders(&scop.gl);
		printf("Loaded shaders\n");
		load_textures(&scop.gl);
		printf("Loaded Textures\n");
		init_open_gl(&scop);
		printf("Initialised OpenGl\n");
		init_midi(&scop);
		printf("Initialised Midi\n");
		setup_render(&scop);
		printf("Setup render\n");
		render(&scop);
	}
	else
		usage();
	return (0);
}
