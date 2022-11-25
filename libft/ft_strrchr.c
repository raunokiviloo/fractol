/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_c;
	char	*string;

	string = (char *)str;
	last_c = NULL;
	while (*string)
	{
		if (*string == (unsigned char)c)
			last_c = string;
		string++;
	}
	if (c == 0)
		last_c = string;
	return (last_c);
}
//Handle c == 0
//Cast int c as unsigned char. 
