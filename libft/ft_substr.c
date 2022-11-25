/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*substring_index;
	size_t	substring_len;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substring = malloc(sizeof(*substring));
		*substring = '\0';
		return (substring);
	}
	substring_len = ft_strlen(s) - start;
	if (len < substring_len)
		substring_len = len;
	substring = malloc(sizeof(*substring) * (substring_len + 1));
	if (!substring)
		return (NULL);
	substring_index = substring;
	while (len-- > 0 && s[start])
		*substring_index++ = s[start++];
	*substring_index = '\0';
	return (substring);
}
/* Peep the malloc syntax - I like it! Works with all types.
Did errorhandling for - s points to NULL; len = 0; start outside s.
Needed to return an empty array instead of NULL when:
 len == 0 or len(s) < start */
