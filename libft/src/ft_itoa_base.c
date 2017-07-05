/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:51:01 by exam              #+#    #+#             */
/*   Updated: 2017/06/09 05:34:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		int_len(int nb, int base)
{
	int		len;

	len = 0;
	if (nb < 0 && base == 10)
		len++;
	while ((nb /= 10) != 0)
		len++;
	return (++len);
}

char			*ft_itoa_base(int value, int base)
{
	int		len;
	int		tmp;
	char	*str;
	char	*b;

	b = ft_strdup("0123456789ABCDEF");
	len = int_len(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	while (value != 0)
	{
		tmp = (value % base);
		if (tmp < 0)
			tmp = -tmp;
		str[len--] = b[tmp];
		value = value / base;
		if (len == 0 && value == 0)
			str[len] = '-';
	}
	return (str);
}
