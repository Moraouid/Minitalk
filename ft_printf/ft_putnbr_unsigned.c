/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:15:34 by sel-abbo          #+#    #+#             */
/*   Updated: 2024/11/22 23:21:28 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	else
	{
		count += ft_putnbr_unsigned(nbr / 10);
		count += ft_putnbr_unsigned(nbr % 10);
	}
	return (count);
}
