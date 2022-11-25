/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack,
const char *needle, size_t bytestocheck)
{
	if (!haystack && bytestocheck == 0)
		return (NULL);
	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	while (*haystack && bytestocheck)
	{
		if (*haystack == *needle)
		{	
			if (ft_strlen(needle) > bytestocheck)
				return (NULL);
			if (!ft_strncmp(haystack, needle, (size_t)ft_strlen(needle)))
				return ((char *)haystack);
		}
		haystack++;
		bytestocheck--;
	}
	return (NULL);
}
