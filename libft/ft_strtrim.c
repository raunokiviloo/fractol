/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:45 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:45 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static char	*blank_arr(void)
{
	char	*blank;

	blank = malloc(sizeof(*blank));
	if (!blank)
		return (NULL);
	blank[0] = '\0';
	return (blank);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			backwrd_index;
	char		*trimmedstr;
	int			trimmedlen;
	char		*trimmed_index;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	while (is_set(*s1, set))
		s1++;
	if (!*s1)
		return (blank_arr());
	backwrd_index = ft_strlen(s1) - 1;
	while (is_set(s1[backwrd_index], set))
		backwrd_index--;
	trimmedlen = &s1[++backwrd_index] - s1;
	trimmedstr = malloc(sizeof(*trimmedstr) * (trimmedlen + 1));
	if (!trimmedstr)
		return (NULL);
	trimmed_index = trimmedstr;
	while (trimmedlen-- > 0)
		*trimmed_index++ = *s1++;
	*trimmed_index = '\0';
	return (trimmedstr);
}
/* Unsure if set is 0-terminated.
Move through string until !set. Set that as trimmedstart. 
Move backwards from strlen until !set. Set that as trimmedend.
Array size = strend - strstart + 1. Write array -> size chars from strstart.
#include <stdio.h>
int main (int argc, char** argv)
{
	if (argc == 3)
	{
		printf("%s", ft_strtrim(argv[1], argv[2]));
	}
} */
