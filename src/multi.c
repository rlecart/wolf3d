/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:15 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:20 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_multi_hook(int key, t_wolf *e)
{
	e += 0;
	if (key == ESC)
		menu(e);
	return (1);
}

void	multi(t_wolf *e)
{
	destroy_windows(e);
	MULTI.win = mlx_new_window(MLX, 1920, 1080, "Wolf3D - Multi");
	mlx_key_hook(MULTI.win, key_multi_hook, e);
}
