/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:00 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		key_credits_hook(int key, t_wolf *e)
{
	e += 0;
	if (key == ESC)
		menu(e);
	return (1);
}

void	credits(t_wolf *e)
{
	destroy_windows(e);
	CRED.win = mlx_new_window(MLX, 1920, 1080, "Wolf3D - Credits");
	mlx_key_hook(CRED.win, key_credits_hook, e);
}
