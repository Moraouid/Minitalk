/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:15 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/22 23:16:41 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(va_list args, const char *frmt)
{
	int		count;
	void	*ptr;

	count = 0;
	if (*frmt == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*frmt == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*frmt == 'd' || *frmt == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*frmt == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*frmt == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), 1);
	else if (*frmt == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), 0);
	else if (*frmt == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (count += ft_putstr("(nil)"), count);
		count += ft_putstr("0x");
		count += ft_puthexa((unsigned long)ptr, 1);
	}
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		count;

	va_start(args, frmt);
	count = 0;
	if (!frmt)
		return (-1);
	while (*frmt)
	{
		if (*frmt == '%' && *(frmt + 1))
		{
			frmt++;
			if (*frmt == '%')
				count += ft_putchar('%');
			else
				count += ft_format(args, frmt);
		}
		else
			count += ft_putchar(*frmt);
		frmt++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	int x = 42;
// 	char *long_string = "This is a very long string...";

// freopen("ft_output.txt", "w", stdout);
// ft_printf("Integer: %d\n", 42);
// ft_printf("Negative integer: %d\n", -42);
// ft_printf("Integer with i: %i\n", 0);
// ft_printf("Unsigned: %u\n", 12345);
// ft_printf("Max unsigned: %u\n", 4294967295U);
// ft_printf("Hexadecimal (lower): %x\n", 255);
// ft_printf("Hexadecimal (zero): %x\n", 0);
// ft_printf("Hexadecimal (upper): %X\n", 255);
// ft_printf("Pointer test: %p\n", &x);
// ft_printf("Null pointer: %p\n", NULL);
// ft_printf("Percent: %%\n");
// ft_printf("Mix: %d, %s, %x, %c\n", 42, "Test", 255, 'Z');
// ft_printf("Empty string: '%s'\n", "");
// ft_printf("Zero: %d\n", 0);
// ft_printf("Large int: %d\n", 2147483647);
// ft_printf("Large unsigned: %u\n", 4294967295U);
// ft_printf("%s\n", long_string);
// ft_printf("Nested: %s\n", "Check %x, %d");

// freopen("std_output.txt", "w", stdout);
// printf("Integer: %d\n", 42);
// printf("Negative integer: %d\n", -42);
// printf("Integer with i: %i\n", 0);
// printf("Unsigned: %u\n", 12345);
// printf("Max unsigned: %u\n", 4294967295U);
// printf("Hexadecimal (lower): %x\n", 255);
// printf("Hexadecimal (zero): %x\n", 0);
// printf("Hexadecimal (upper): %X\n", 255);
// printf("Pointer test: %p\n", &x);
// printf("Null pointer: %p\n", NULL);
// printf("Percent: %%\n");
// printf("Mix: %d, %s, %x, %c\n", 42, "Test", 255, 'Z');
// printf("Empty string: '%s'\n", "");
// printf("Zero: %d\n", 0);
// printf("Large int: %d\n", 2147483647);
// printf("Large unsigned: %u\n", 4294967295U);
// printf("%s\n", long_string);
// printf("Nested: %s\n", "Check %x, %d");
// }
/* int main()
{
	printf("%d\n", printf(NULL));
} */