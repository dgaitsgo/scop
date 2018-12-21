/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:46:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/12/20 20:56:14 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WINDOW_H
# define __WINDOW_H

# include "/nfs/2017/d/dgaitsgo/Library/Frameworks/SDL2.framework/Headers/SDL.h"

# define WINDOW					t_window
# define WIN_WIDTH				800.0f
# define WIN_HEIGHT				600.0f
# define Z_NEAR					0.01f
# define Z_FAR					100000.0f
# define ASPECT_RATIO			WIN_WIDTH/WIN_HEIGHT
# define FOV					70.0f
# define DEFAULT_COLOR_DEPTH	32
# define SDL_WINDOW				window->window
# define SDL_SCREEN				window->screen
# define SDL_IMAGE				window->image
# define SDL_FRAME_BUFFER		window->frame_buffer
# define SDL_WIDTH				window->width
# define SDL_HEIGHT				window->height
# define SDL_DEPTH				window->depth
# define SDL_BPL				window->bytes_per_line
# define SDL_EVENT				window->event
# define KEY					SDL_EVENT.key.keysym.sym

typedef	struct					s_sdlwindow
{
	SDL_DisplayMode				mode;
	SDL_Window					*window;
	SDL_Surface					*screen;
	SDL_Surface					*image;
	SDL_GLContext				gl_context;
	char						*frame_buffer;
	SDL_Event					event;
	int							width;
	int							height;
	int							depth;
	int							bytes_per_line;
	int							flags;
}								t_window;

void							init_window(WINDOW *window, char *title);
void							kill_sdl(WINDOW *window);
void							reset_mouse(t_window *window);
#endif
