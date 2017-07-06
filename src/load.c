/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_load_hook(int key, t_wolf *e)
{
	e += 0;
	if (key == ESC)
		menu(e);
	return (1);
}

void	load(t_wolf *e)
{
	destroy_windows(e);
	LOAD.win = mlx_new_window(MLX, 1920, 1080, "Wolf3D - Load");
	mlx_key_hook(LOAD.win, key_load_hook, e);
}
