/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:32:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 22:30:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

SDL_Texture		*load_image(t_wolf *e, const char *path)
{
	SDL_Surface		*sdl_surface;

	sdl_surface = SDL_LoadBMP(path);
	return (SDL_CreateTextureFromSurface(e->framebuffer->sdl_renderer, sdl_surface));
}

void			init_menu(t_wolf *e)
{
	MENU.wtl = 0;
	MENU.bol = 0;
	MENU.bg = load_image(e,"img/bmp/menu_bg.bmp");
	MENU.sure = load_image(e,"img/bmp/menu_bg_exit.bmp");
	MENU.quit1 = load_image(e,"img/bmp/quit1.bmp");
	MENU.quit2 = load_image(e,"img/bmp/quit2.bmp");
	MENU.but.solo1 = load_image(e,"img/bmp/m_11.bmp");
	MENU.but.solo2 = load_image(e,"img/bmp/m_12.bmp");
	MENU.but.isload = 0;
	MENU.but.load1 = load_image(e,"img/bmp/m_20.bmp");
	MENU.but.load2 = load_image(e,"img/bmp/m_21.bmp");
	MENU.but.load3 = load_image(e,"img/bmp/m_22.bmp");
	MENU.but.multi1 = load_image(e,"img/bmp/m_31.bmp");
	MENU.but.multi2 = load_image(e,"img/bmp/m_32.bmp");
	MENU.but.options1 = load_image(e,"img/bmp/m_41.bmp");
	MENU.but.options2 = load_image(e,"img/bmp/m_42.bmp");
	MENU.but.credits1 = load_image(e,"img/bmp/m_51.bmp");
	MENU.but.credits2 = load_image(e,"img/bmp/m_52.bmp");
	MENU.but.exit1 = load_image(e,"img/bmp/m_61.bmp");
	MENU.but.exit2 = load_image(e,"img/bmp/m_62.bmp");
	MENU.desc.solo = load_image(e,"img/bmp/m_d1.bmp");
	MENU.desc.load = load_image(e,"img/bmp/m_d2.bmp");
	MENU.desc.multi = load_image(e,"img/bmp/m_d3.bmp");
	MENU.desc.options = load_image(e,"img/bmp/m_d4.bmp");
	MENU.desc.credits = load_image(e,"img/bmp/m_d5.bmp");
	MENU.desc.exit = load_image(e,"img/bmp/m_d6.bmp");
}

int		init(t_wolf *e)
{
	new_sdl_display(e, "Wolf3D", 1920, 1080);
	e->framebuffer = new_bitmap(e, e->win->w, e->win->h);
	init_menu(e);
	return (0);
}
