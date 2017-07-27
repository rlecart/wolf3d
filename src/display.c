/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:50:10 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 22:30:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	new_sdl_display(t_wolf *e, const char *title, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error("sdl error: unable to initialize sdl !");
	e->sdl_win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											width,
											height,
											0);
	if (!e->sdl_win)
		error("sdl error: unable to create window !");
	e->win->w = width;
	e->win->h = height;
	e->win->name = (char *)title;
}

void	sdl_loop(t_wolf *e, int (*loop)(t_wolf *))
{
	SDL_Event event;

	SDL_SetRenderDrawColor(e->framebuffer->sdl_renderer, 255, 0, 255, 255);
	SDL_RenderPresent(e->framebuffer->sdl_renderer);
	SDL_RenderClear(e->framebuffer->sdl_renderer);
	while (1)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT ||
				(event.type == SDL_KEYDOWN &&
				event.key.keysym.sym == SDLK_ESCAPE))
				exit(0);
		}
		loop(e);
	}
}
