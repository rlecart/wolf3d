/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:33:44 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*ft_intnew(size_t len)
{
	int			*i;
	size_t		j;

	j = 0;
	if (!(i = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (j < len)
		i[j++] = 0;
	return (i);
}
