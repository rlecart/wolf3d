/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:55:35 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 22:28:54 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_menu_hook(int key, t_wolf *e)
{
	if (!MENU.wtl)
	{
		if (key == ESC)
		{
			quit(e);
			MENU.wtl = (!MENU.wtl) ? 1 : 0;
		}
		if (key == SPACE)
		{
			MENU.but.isload = (!MENU.but.isload) ? 1 : 0;
			display_menu_classic(e);
		}
	}
	else if (key == ESC)
		exit(0);
	return (1);
}

int		mouse_motion_hook_menu(int x, int y, t_wolf *e)
{
	if (!MENU.wtl)
	{
		display_menu_classic(e);
		if (x >= 165 && y >= 382 && x <= 613 && y <= 463)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.solo2, 165, 382);
		else if (MENU.but.isload
				&& x >= 165 && y >= 464 && x <= 613 && y <= 530)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.load3, 165, 449);
		else if (x >= 165 && y >= 531 && x <= 613 && y <= 598)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.multi2, 165, 516);
		else if (x >= 165 && y >= 599 && x <= 613 && y <= 666)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.options2, 165, 582);
		else if (x >= 165 && y >= 667 && x <= 613 && y <= 734)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.credits2, 165, 649);
		else if (x >= 165 && y >= 735 && x <= 613 && y <= 802)
			draw_texture(e->framebuffer->sdl_renderer,
					MENU.but.exit2, 165, 715);
		display_desc(x, y, e);
	}
	return (1);
}

void	confirmation(t_wolf *e)
{
	if (MENU.bol)
	{
		MENU.no[0] = 1920 / 2 - 519 / 2 + 24;
		MENU.no[1] = MENU.no[0] + 120;
		MENU.no[2] = 1080 / 2 - 657 / 2 + 30;
		MENU.no[3] = MENU.no[2] + 120;
		MENU.yes[0] = MENU.no[0] + 350;
		MENU.yes[1] = MENU.no[1] + 350;
		MENU.yes[2] = MENU.no[2];
		MENU.yes[3] = MENU.no[3];
	}
	else
	{
		MENU.no[0] = 1920 / 2 - 450 / 2;
		MENU.no[1] = MENU.no[0] + 226;
		MENU.no[2] = 1080 / 2 - 657 / 2 + 577;
		MENU.no[3] = MENU.no[2] + 226;
		MENU.yes[0] = MENU.no[0] + 350;
		MENU.yes[1] = MENU.no[1] + 350;
		MENU.yes[2] = MENU.no[2];
		MENU.yes[3] = MENU.no[3];
	}
}

void	leave(int x, int y, t_wolf *e)
{
	confirmation(e);
	if (x >= MENU.no[0] && y >= MENU.no[2]
			&& x <= MENU.no[1] && y <= MENU.no[3])
	{
		MENU.wtl = (!MENU.wtl) ? 1 : 0;
		menu(e);
	}
	else if (x >= MENU.yes[0] && y >= MENU.yes[2]
			&& x <= MENU.yes[1] && y <= MENU.yes[3])
		exit(0);
}

int		mouse_menu_hook(int button, int x, int y, t_wolf *e)
{
	if (!MENU.wtl && button == 1)
	{
		if (x >= 165 && y >= 382 && x <= 613 && y <= 463)
			solo(e);
		else if (MENU.but.isload
				&& x >= 165 && y >= 464 && x <= 613 && y <= 530)
			load(e);
		else if (x >= 165 && y >= 531 && x <= 613 && y <= 598)
			multi(e);
		else if (x >= 165 && y >= 599 && x <= 613 && y <= 666)
			options(e);
		else if (x >= 165 && y >= 667 && x <= 613 && y <= 734)
			credits(e);
		else if (x >= 165 && y >= 735 && x <= 613 && y <= 802)
		{
			quit(e);
			MENU.wtl = (!MENU.wtl) ? 1 : 0;
		}
	}
	else if (MENU.wtl && button == 1)
		leave(x, y, e);
	return (1);
}
