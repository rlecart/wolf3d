/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 00:03:29 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 01:23:20 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	display_menu_classic(t_wolf *e)
{
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.bg, 0, 0);
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.solo1, 165, 382);
	if (e->menu.buttons.isload < 0)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.load1, 165, 449);
	else
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.load2, 165, 449);
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.multi1, 165, 516);
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.options1, 165, 582);
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.credits1, 165, 649);
	mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.exit1, 165, 715);
}

int		key_menu_hook(int key, t_wolf *e)
{
	if (key == ESC)
		exit(0);
	if (key == SPACE)
		e->menu.buttons.isload *= -1;
	display_menu_classic(e);
	return (1);
}

int		mouse_motion_hook_menu(int x, int y, t_wolf *e)
{
	display_menu_classic(e);
	if (x >= 165 && y >= 382 && x <= 613 && y <= 463)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.solo2, 165, 382);
	else if (e->menu.buttons.isload == 1 && x >= 165 && y >= 464 && x <= 613 && y <= 530)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.load3, 165, 449);
	else if (x >= 165 && y >= 531 && x <= 613 && y <= 598)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.multi2, 165, 516);
	else if (x >= 165 && y >= 599 && x <= 613 && y <= 666)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.options2, 165, 582);
	else if (x >= 165 && y >= 667 && x <= 613 && y <= 734)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.credits2, 165, 649);
	else if (x >= 165 && y >= 735 && x <= 613 && y <= 802)
		mlx_put_image_to_window(e->mlx, e->menu.win, e->menu.buttons.exit2, 165, 715);
	return (1);
}

void	menu(t_wolf *e)
{
	mlx_key_hook(e->menu.win, key_menu_hook, e);
	mlx_hook(e->menu.win, 6, (1L << 6), mouse_motion_hook_menu, e);
	display_menu_classic(e);
}
