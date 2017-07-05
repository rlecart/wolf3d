/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:27:39 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:11 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strtabnew(int x, int y)
{
	int		i;
	char	**str;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	while (i < x)
		if (!(str[i++] = ft_strnew(y)))
			return (NULL);
	str[i] = NULL;
	return (str);
}
