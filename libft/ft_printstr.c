/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:21 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/14 16:32:23 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printstr(char *str)
{
	int	lettercount;

	lettercount = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (*str)
	{
		write(1, str, 1);
		lettercount++;
		str++;
	}
	return (lettercount);
}
