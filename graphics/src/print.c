/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:14:14 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:38:30 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>

void	reset(char *img)
{
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
		img[i++] = '\0';
}

void	print(t_key *k)
{
	static int		bol = 0;

	if (bol == 0)
	{
		k->blackscreen = mlx_new_image(k->mlx, WIN_W, WIN_H);
		bol = 1;
	}
	mlx_put_image_to_window(k->mlx, k->win, k->blackscreen, 0, 0);
	mlx_put_image_to_window(k->mlx, k->win, k->data, 0, 0);
	reset(k->img);
}
