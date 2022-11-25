/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t bytestocheck)
{
	unsigned char	*string;
	unsigned char	character;

	string = (unsigned char *)str;
	character = (unsigned char)c;
	while (bytestocheck-- > 0)
		if (*string++ == character)
			return ((void *)(string - 1));
	return (NULL);
}
// Had error where I returned 0 if !str. 
