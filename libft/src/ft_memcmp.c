/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:26:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	unsigned int	i;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return ((unsigned char)s1_cpy[i] - (unsigned char)s2_cpy[i]);
		i++;
	}
	return (0);
}
