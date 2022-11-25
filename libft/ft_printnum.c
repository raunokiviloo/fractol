/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:16:10 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/16 14:16:11 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printnum(int num)
{
	char	*number;
	int		byteswritten;

	number = ft_itoa(num);
	byteswritten = ft_printstr(number);
	free(number);
	return (byteswritten);
}
