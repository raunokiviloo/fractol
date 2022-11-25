/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	char			*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest == source)
		return (dest);
	if (dest < source)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		dest[i - 1] = source[i - 1];
		i--;
	}
	return (dest);
}
/*Using temp array prevents data loss when src and dst memory is overlapping.
Copy forward if dst < src, copy backwards if dst > src.*/
