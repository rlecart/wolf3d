/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:27:39 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		**ft_inttabnew(int x, int y)
{
	int		i;
	int		**nbr;

	i = 0;
	if (!(nbr = (int**)malloc(sizeof(int*) * (x + 1))))
		return (NULL);
	while (i < x)
		if (!(nbr[i++] = ft_intnew(y)))
			return (NULL);
	nbr[i] = NULL;
	return (nbr);
}
