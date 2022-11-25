/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	char	*newstring_index;

	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(sizeof(*newstring)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstring)
		return (NULL);
	newstring_index = newstring;
	while (*s1)
		*newstring_index++ = *s1++;
	while (*s2)
		*newstring_index++ = *s2++;
	*newstring_index = '\0';
	return (newstring);
}

//What if !s1 or !s2? Someone had just returned NULL. 
/*#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
	printf("%s", ft_strjoin(argv[1], argv[2]));
	}
}
*/
