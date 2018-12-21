/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:34:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 20:55:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			set_sdl_attributes(void)
{
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_ShowCursor(SDL_DISABLE);
}

void			init_window(WINDOW *window, char *title)
{
	int x_offset;
	int y_offset;

	SDL_DEPTH = DEFAULT_COLOR_DEPTH;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / DEFAULT_COLOR_DEPTH / 3);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GetCurrentDisplayMode(0, &window->mode);
	SDL_WIDTH = window->mode.w;
	SDL_HEIGHT = window->mode.h;
	set_sdl_attributes();
	x_offset = (window->mode.w - SDL_WIDTH) / 2;
	y_offset = (window->mode.h - SDL_HEIGHT) / 2;
	SDL_WINDOW = SDL_CreateWindow(title,
									x_offset,
									y_offset,
									SDL_WIDTH,
									SDL_HEIGHT,
									SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	SDL_SetWindowFullscreen(SDL_WINDOW, SDL_WINDOW_FULLSCREEN_DESKTOP);
	window->gl_context = SDL_GL_CreateContext(SDL_WINDOW);
}

void			kill_sdl(WINDOW *window)
{
	SDL_Quit();
	exit(0);
	free(window);
}
