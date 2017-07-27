/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 00:03:29 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 21:50:16 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	quit(t_wolf *e)
{
	int				x[2];
	int				y[2];

	x[0] = 1920 / 2 - 519 / 2;
	y[0] = 1080 / 2 - 657 / 2;
	x[1] = 1920 / 2 - 450 / 2;
	y[1] = 1080 / 2 - 657 / 2;
	mlx_put_image_to_window(MLX, MENU.win, MENU.sure, 0, 0);
	if (!MENU.bol)
		mlx_put_image_to_window(MLX, MENU.win, MENU.quit1, x[0], y[0]);
	else
		mlx_put_image_to_window(MLX, MENU.win, MENU.quit2, x[1], y[1]);
	MENU.bol = (!MENU.bol) ? 1 : 0;
}

void	display_menu_classic(t_wolf *e)
{
	mlx_put_image_to_window(MLX, MENU.win, MENU.bg, 0, 0);
	mlx_put_image_to_window(MLX, MENU.win, MENU.but.solo1, 165, 382);
	if (!MENU.but.isload)
		mlx_put_image_to_window(MLX, MENU.win, MENU.but.load1, 165, 449);
	else
		mlx_put_image_to_window(MLX, MENU.win, MENU.but.load2, 165, 449);
	mlx_put_image_to_window(MLX, MENU.win, MENU.but.multi1, 165, 516);
	mlx_put_image_to_window(MLX, MENU.win, MENU.but.options1, 165, 582);
	mlx_put_image_to_window(MLX, MENU.win, MENU.but.credits1, 165, 649);
	mlx_put_image_to_window(MLX, MENU.win, MENU.but.exit1, 165, 715);
}

void	display_desc(int x, int y, t_wolf *e)
{
	if (x >= 165 && y >= 382 && x <= 613 && y <= 463)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.solo, 165, 884);
	else if (MENU.but.isload && x >= 165 && y >= 464 && x <= 613 && y <= 530)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.load, 165, 884);
	else if (x >= 165 && y >= 531 && x <= 613 && y <= 598)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.multi, 165, 884);
	else if (x >= 165 && y >= 599 && x <= 613 && y <= 666)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.options, 165, 884);
	else if (x >= 165 && y >= 667 && x <= 613 && y <= 734)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.credits, 165, 884);
	else if (x >= 165 && y >= 735 && x <= 613 && y <= 802)
		mlx_put_image_to_window(MLX, MENU.win, MENU.desc.exit, 165, 884);
}

void	menu(t_wolf *e)
{
	display_menu_classic(e);
}
