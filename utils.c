/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:59 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/23 12:02:08 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_join(char *s1, char s2)
{
	int		i;
	char	*res;
	size_t	len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	res = (char *)malloc(len_s1 + 2);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = s2;
	res[i+1] = '\0';
	return (res);
}
