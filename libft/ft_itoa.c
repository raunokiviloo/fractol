/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:43 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:43 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
/*
- We want to know how many digits there are to allocate memory. 
- Use int long to handle INT_MIN when working with abs values.  
*/
//Really elegant intlen imo. Works for negatives and handles 0. 
static int	getintlen(int n)
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

char	*ft_itoa(int n)
{
	int long		num;
	char			*num_arr;
	unsigned int	numlen;

	num = n;
	numlen = getintlen(n);
	if (num < 0)
	{
		num *= -1;
		numlen++;
	}
	num_arr = malloc(numlen + 1);
	if (!num_arr)
		return (NULL);
	num_arr[numlen] = '\0';
	if (n < 0)
		num_arr[0] = '-';
	if (num == 0)
		num_arr[--numlen] = 48;
	while (num)
	{
		num_arr[--numlen] = num % 10 + 48;
		num /= 10;
	}
	return (num_arr);
}
/*int main(void)
{
	int value = 4242;
	printf("%s\n", ft_itoa(value));
	value = 0;
	printf("%s\n", ft_itoa(value));
	value = -2147483648;
	printf("%s\n", ft_itoa(value));
	value = 2147483647;
	printf("%s\n", ft_itoa(value));
}*/
