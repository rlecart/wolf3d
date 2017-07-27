/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 22:11:46 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 22:30:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_texture(SDL_Renderer *rend, SDL_Texture *img, int x, int y)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = img->w;
	rect.h = img->h;
	SDL_RenderCopy(rend, img, NULL, &rect);
}
