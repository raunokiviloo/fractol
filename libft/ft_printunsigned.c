/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:49:20 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/16 14:49:22 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	getintlen(unsigned int n)
{
	int	len;

	len = !n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*num_arr;
	unsigned int	numlen;

	numlen = getintlen(n);
	num_arr = malloc(numlen + 1);
	if (!num_arr)
		return (NULL);
	num_arr[numlen] = '\0';
	if (n == 0)
		num_arr[0] = '0';
	while (n)
	{
		num_arr[--numlen] = n % 10 + 48;
		n /= 10;
	}
	return (num_arr);
}

int	ft_printunsigned(unsigned int num)
{
	char	*number;
	int		byteswritten;

	number = ft_uitoa(num);
	byteswritten = ft_printstr(number);
	free(number);
	return (byteswritten);
}
