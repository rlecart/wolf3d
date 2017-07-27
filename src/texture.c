/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 22:11:46 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 22:49:58 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_texture(SDL_Renderer *rend, struct SDL_Texture *img, int x, int y)
{
	SDL_Rect	rect;
	int			w;
	int			h;

	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(rend, img, NULL, &rect);
}
