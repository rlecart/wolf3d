/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:32:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:41:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	destroy_windows(t_wolf *e)
{
	if (MENU.win)
	{
		mlx_destroy_window(MLX, MENU.win);
		MENU.win = NULL;
	}
	if (SOLO.win)
	{
		mlx_destroy_window(MLX, SOLO.win);
		SOLO.win = NULL;
	}
	if (e->load.win)
	{
		mlx_destroy_window(MLX, e->load.win);
		e->load.win = NULL;
	}
	if (e->multi.win)
	{
		mlx_destroy_window(MLX, e->multi.win);
		e->multi.win = NULL;
	}
	if (e->options.win)
	{
		mlx_destroy_window(MLX, e->options.win);
		e->options.win = NULL;
	}
	if (e->credits.win)
	{
		mlx_destroy_window(MLX, e->credits.win);
		e->credits.win = NULL;
	}
}

void	init_menu(t_wolf *e)
{
	int		i;

	MENU.wtl = 0;
	MENU.bol = 0;
	MENU.bg = mlx_xpm_file_to_image(MLX, "img/xpm/menu_bg.xpm", &i, &i);
	MENU.sure = mlx_xpm_file_to_image(MLX, "img/xpm/menu_bg_exit.xpm", &i, &i);
	MENU.quit1 = mlx_xpm_file_to_image(MLX, "img/xpm/quit1.xpm", &i, &i);
	MENU.quit2 = mlx_xpm_file_to_image(MLX, "img/xpm/quit2.xpm", &i, &i);
	MENU.but.solo1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_11.xpm", &i, &i);
	MENU.but.solo2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_12.xpm", &i, &i);
	MENU.but.isload = 0;
	MENU.but.load1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_20.xpm", &i, &i);
	MENU.but.load2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_21.xpm", &i, &i);
	MENU.but.load3 = mlx_xpm_file_to_image(MLX, "img/xpm/m_22.xpm", &i, &i);
	MENU.but.multi1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_31.xpm", &i, &i);
	MENU.but.multi2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_32.xpm", &i, &i);
	MENU.but.options1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_41.xpm", &i, &i);
	MENU.but.options2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_42.xpm", &i, &i);
	MENU.but.credits1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_51.xpm", &i, &i);
	MENU.but.credits2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_52.xpm", &i, &i);
	MENU.but.exit1 = mlx_xpm_file_to_image(MLX, "img/xpm/m_61.xpm", &i, &i);
	MENU.but.exit2 = mlx_xpm_file_to_image(MLX, "img/xpm/m_62.xpm", &i, &i);
	MENU.desc.solo = mlx_xpm_file_to_image(MLX, "img/xpm/m_d1.xpm", &i, &i);
	MENU.desc.load = mlx_xpm_file_to_image(MLX, "img/xpm/m_d2.xpm", &i, &i);
	MENU.desc.multi = mlx_xpm_file_to_image(MLX, "img/xpm/m_d3.xpm", &i, &i);
	MENU.desc.options = mlx_xpm_file_to_image(MLX, "img/xpm/m_d4.xpm", &i, &i);
	MENU.desc.credits = mlx_xpm_file_to_image(MLX, "img/xpm/m_d5.xpm", &i, &i);
	MENU.desc.exit = mlx_xpm_file_to_image(MLX, "img/xpm/m_d6.xpm", &i, &i);
}

int		init(t_wolf *e)
{
	MLX = mlx_init();
	MENU.win = NULL;
	SOLO.win = NULL;
	LOAD.win = NULL;
	MULTI.win = NULL;
	OPT.win = NULL;
	CRED.win = NULL;
	init_menu(e);
	return (0);
}
