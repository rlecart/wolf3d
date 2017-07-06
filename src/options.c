/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:25 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_options_hook(int key, t_wolf *e)
{
	e += 0;
	if (key == ESC)
		menu(e);
	return (1);
}

void	options(t_wolf *e)
{
	destroy_windows(e);
	OPT.win = mlx_new_window(MLX, 1920, 1080, "Wolf3D - Options");
	mlx_key_hook(OPT.win, key_options_hook, e);
}
