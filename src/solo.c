/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:36 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_solo_hook(int key, t_wolf *e)
{
	e += 0;
	if (key == ESC)
		menu(e);
	return (1);
}

void	solo(t_wolf *e)
{
	destroy_windows(e);
	SOLO.win = mlx_new_window(MLX, 1920, 1080, "Wolf3D - Solo");
	mlx_key_hook(SOLO.win, key_solo_hook, e);
}
