/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:29:44 by rkiviloo          #+#    #+#             */
/*   Updated: 2022/10/14 14:29:46 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_print_type(char type, va_list var_args)
{
	if (type == 'c')
		return (ft_printchr(va_arg(var_args, int)));
	if (type == 's')
		return (ft_printstr(va_arg(var_args, char *)));
	if (type == 'p')
		return (ft_printptr(va_arg(var_args, unsigned long long)));
	if (type == 'd' || type == 'i')
		return (ft_printnum(va_arg(var_args, int)));
	if (type == 'u')
		return (ft_printunsigned(va_arg(var_args, unsigned int)));
	if (type == 'X' || type == 'x')
		return (ft_printhex(va_arg(var_args, unsigned int), type));
	if (type == '%')
		return (ft_printpercent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		chrsprinted;

	va_start(var_args, str);
	chrsprinted = 0;
	while (*str)
	{
		if (*str == '%')
		{
			chrsprinted += ft_print_type(*++str, var_args);
			str++;
		}
		else
		{
			chrsprinted += ft_printchr(*str);
			str++;
		}
	}
	return (chrsprinted);
}

/*int main(void)
{
	char chr = 'm';
	char chr2 = 't';
	printf("Substitute CHAR:\n");
	printf("The %cake is a %cie!", chr, chr2);	
	printf(" <--- printf\n");	
	ft_printf("The %cake is a %cie!", chr, chr2);
	printf(" <--- ft_printf\n\n");
	
	char* str = "cake";
	char* str2 = "lie";

	printf("Substitute STRING:\n");
	printf("The %s is a %s!", str, str2);	
	printf(" <--- printf\n");	
	ft_printf("The %s is a %s!", str, str2);
	printf(" <--- ft_printf\n\n");
	
	char* str3 = "cake";
	char* str4 = "lie";

	printf("Substitute POINTER:\n");
	printf("The %p is a %p!", str3, str4);	
	printf(" <--- printf\n");	
	ft_printf("The %p is a %p!", str3, str4);
	printf(" <--- ft_printf\n\n");		
	
	int int1 = 42;
	int int2 = -9999;

	printf("Substitute INT:\n");
	printf("The %i is a %d!", int1, int2);	
	printf(" <--- printf\n");	
	ft_printf("The %i is a %d!", int1, int2);
	printf(" <--- ft_printf\n\n");	
	
	unsigned int int3 = 1111111111;
	unsigned int int4 = 4293966180;

	printf("Substitute UINT:\n");
	printf("The %u is a %u!", int3, int4);	
	printf(" <--- printf\n");	
	ft_printf("The %u is a %u!", int3, int4);
	printf(" <--- ft_printf\n\n");
	
	unsigned int int5 = 111111;
	unsigned int int6 = 4242424242;

	printf("Substitute HEX:\n");
	printf("The %x is a %X!", int5, int6);	
	printf(" <--- printf\n");	
	ft_printf("The %x is a %X!", int5, int6);
	printf(" <--- ft_printf\n\n");
	
	printf("Substitute PERCENT:\n");
	printf("The %% is a %%!");	
	printf(" <--- printf\n");	
	ft_printf("The %% is a %%!");
	printf(" <--- ft_printf\n\n");					
}*/
