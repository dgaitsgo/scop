/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/18 20:08:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

void	center_model_in_view(t_camera *c, t_model *m)
{
	t_vector pos;
	t_vector direction;

	pos = new_vector(
					m->bv.center.x,
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
	glUniform1f(
		scop->gl.uniform_refs[MODEL_RADIUS],
		scop->model.bv.diameter / 2);
}

int		main(int argc, char **argv)
{
	t_scop	scop;
	FILE	*fd;

	scop.polygon_mode = 0;
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		assert(fd != NULL);
		init_window(&scop.window, argv[1], (int)WIN_WIDTH, (int)WIN_HEIGHT);
		init_model(&scop.model);
		init_camera(&scop.camera);
		load_obj(&scop.model, fd);
		load_shaders(&scop.gl);
		load_textures(&scop.gl);
		init_open_gl(&scop);
		init_midi(&scop);
		setup_render(&scop);
		render(&scop);
	}
	else
		usage();
	return (0);
}
