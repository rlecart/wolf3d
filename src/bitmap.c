/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:40:53 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 22:30:12 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_bitmap	*new_bitmap(t_wolf *e, int width, int height)
{
	t_bitmap	*b;

	if (!(b = (t_bitmap *)ft_memalloc(sizeof(t_bitmap))))
		error("malloc error !");
	b->sdl_renderer = SDL_CreateRenderer(e->sdl_win, -1, 0);
	b->sdl_texture = SDL_CreateTexture(b->sdl_renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
	if (!(b->pixels = ft_memalloc(sizeof(int) * width * height)))
		error("malloc error !");
	b->width = width;
	b->height = height;
	return (b);
}

void	bitmap_draw_pix(t_bitmap *b, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= b->width || y >= b->height)
		return ;
	b->pixels[x + y * b->width] = color;
}

void	bitmap_update(t_bitmap *b)
{
	SDL_UpdateTexture(b->sdl_texture, NULL, b->pixels, b->width * sizeof(int));
	SDL_RenderCopy(b->sdl_renderer, b->sdl_texture, NULL, NULL);
	SDL_RenderPresent(b->sdl_renderer);
}

void	clear_bitmap(t_bitmap *b)
{
	int		x;
	int		y;

	y = -1;
	while (++y < b->height)
	{
		x = -1;
		while (++x < b->width)
			bitmap_draw_pix(b, x, y, 0);
	}
}
