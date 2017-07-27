/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:15 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 22:29:51 by rlecart          ###   ########.fr       */
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
	e += 0;
}
