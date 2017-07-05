/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:32:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 01:17:57 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
void	init_menu(t_wolf *e)
{
	int		i;

	e->menu.win = mlx_new_window(e->mlx, 1920, 1080, "Wolf3D - Menu");
	e->menu.bg = mlx_xpm_file_to_image(e->mlx, "img/xpm/menu_bg.xpm", &i, &i);
	e->menu.buttons.solo1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_11.xpm", &i, &i);
	e->menu.buttons.solo2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_12.xpm", &i, &i);
	e->menu.buttons.isload = -1;
	e->menu.buttons.load1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_20.xpm", &i, &i);
	e->menu.buttons.load2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_21.xpm", &i, &i);
	e->menu.buttons.load3 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_22.xpm", &i, &i);
	e->menu.buttons.multi1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_31.xpm", &i, &i);
	e->menu.buttons.multi2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_32.xpm", &i, &i);
	e->menu.buttons.options1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_41.xpm", &i, &i);
	e->menu.buttons.options2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_42.xpm", &i, &i);
	e->menu.buttons.credits1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_51.xpm", &i, &i);
	e->menu.buttons.credits2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_52.xpm", &i, &i);
	e->menu.buttons.exit1 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_61.xpm", &i, &i);
	e->menu.buttons.exit2 = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_62.xpm", &i, &i);
	e->menu.desc.solo = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d1.xpm", &i, &i);
	e->menu.desc.load = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d2.xpm", &i, &i);
	e->menu.desc.multi = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d3.xpm", &i, &i);
	e->menu.desc.options = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d4.xpm", &i, &i);
	e->menu.desc.credits = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d5.xpm", &i, &i);
	e->menu.desc.exit = mlx_xpm_file_to_image(e->mlx, "img/xpm/m_d6.xpm", &i, &i);
}

int		init(t_wolf *e)
{
	e->mlx = mlx_init();
	init_menu(e);
	return (0);
}
