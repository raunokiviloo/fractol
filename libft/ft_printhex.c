/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:49:42 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/16 14:49:43 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_printhex_rec(unsigned int num, int *byteswritten, char type)
{
	if (num >= 16)
	{
		ft_printhex_rec(num / 16, byteswritten, type);
		ft_printhex_rec(num % 16, byteswritten, type);
	}
	else
	{
		if (num <= 9)
			*byteswritten += ft_printchr('0' + num);
		else
		{
			if (type == 'x')
				*byteswritten += ft_printchr('a' + num % 10);
			if (type == 'X')
				*byteswritten += ft_printchr('A' + num % 10);
		}
	}
}

int	ft_printhex(unsigned int num, char type)
{
	int	byteswritten;

	byteswritten = 0;
	if (!num)
		byteswritten += ft_printchr('0');
	else
		ft_printhex_rec(num, &byteswritten, type);
	return (byteswritten);
}
