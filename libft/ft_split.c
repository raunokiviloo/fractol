/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:02:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/07 10:02:44 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static unsigned int	getwordcount(char const *str, char delimiter)
{
	unsigned int	count;

	count = 0;
	while (*str == delimiter && *str)
		str++;
	if (*str)
		count++;
	while (*str)
	{
		if (*str == delimiter && *(str + 1) != delimiter
			&& *(str + 1) != '\0')
			count++;
		str++;
	}
	return (count);
}

static void	freeall(char **target, int arr_index)
{
	while (arr_index >= 0)
		free(target[arr_index--]);
}

static int	alloc_toks(char const *str, char delimiter, char **target,
		unsigned int wordcount)
{
	int				arr_index;
	unsigned int	lettercount;

	arr_index = 0;
	lettercount = 0;
	while (*str && wordcount--)
	{
		while (*str == delimiter)
			str++;
		while (*str != delimiter && *str != '\0')
		{
			lettercount++;
			str++;
		}
		if (lettercount)
			target[arr_index] = malloc(sizeof(**target) * (lettercount + 1));
		if (!target[arr_index])
		{
			freeall(target, arr_index);
			return (0);
		}
		lettercount = 0;
		arr_index++;
	}
	return (1);
}

static void	write_toks(char const *str, char delimiter,
		char **target, unsigned int wordcount)
{
	int				arr_index;
	unsigned int	char_index;

	arr_index = 0;
	while (*str && wordcount-- > 0)
	{
		char_index = 0;
		while (*str == delimiter)
			str++;
		while (*str != delimiter && *str != '\0')
		{
			target[arr_index][char_index] = *str;
			char_index++;
			str++;
		}
		target[arr_index][char_index] = '\0';
		arr_index++;
	}
	target[arr_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**tokens;
	unsigned int	wordcount;

	if (!s)
		return (NULL);
	wordcount = getwordcount(s, c);
	tokens = malloc(sizeof(*tokens) * (wordcount + 1));
	if (!tokens)
		return (NULL);
	if (!alloc_toks(s, c, tokens, wordcount))
	{
		free(tokens);
		return (NULL);
	}
	write_toks(s, c, tokens, wordcount);
	return (tokens);
}
// If we have an array of strings **arr ->
// sizeof(**arr) == 1 byte - char
// sizeof(*arr) == -> 4 / 8 bytes depending on environment. - ptr 
/*
int	main(void)
{
	char	**tabstr;
	int i = 0;
	char **output;
	char *test1 = "TESTME";
	char delimiter = ' ';
	printf("String: %s\n", test1);
	printf("Delimiter: %c\n", delimiter);
	printf("Substrings: ");
	output = ft_split(test1, delimiter);
	while (output != NULL && *output != NULL)
		printf("\n-> %s", *output++);
	printf("\n-----------------------\n");
}*/
