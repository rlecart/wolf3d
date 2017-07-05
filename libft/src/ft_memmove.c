/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:38:30 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*src_cpy;
	char		*dst_cpy;

	i = -1;
	src_cpy = (char*)src;
	dst_cpy = (char*)dst;
	if (dst_cpy > src_cpy)
	{
		while ((int)--len >= 0)
			dst_cpy[len] = src_cpy[len];
	}
	else
	{
		while (++i < len)
			dst_cpy[i] = src_cpy[i];
	}
	return (dst);
}
