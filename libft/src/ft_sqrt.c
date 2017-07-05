/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:07:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:34:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static double	ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

double			ft_sqrt(double nb)
{
	double result;
	double range;

	range = nb * 0.001;
	result = 1;
	while (ft_abs(result * result - nb) > range)
		result = (result + nb / result) / 2;
	return (result);
}
