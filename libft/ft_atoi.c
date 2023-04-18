/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:06:00 by macote            #+#    #+#             */
/*   Updated: 2023/02/21 11:05:31 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_negative;
	int	resultat;

	if (!str)
		return (0);
	is_negative = 0;
	resultat = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		is_negative = ++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10;
		resultat += (str[i] - 48);
		i++;
	}
	if (is_negative)
		resultat *= -1;
	return (resultat);
}

// int main()
// {
// 	// printf("%d\n", atoi("-2147483647"));
// 	printf("%d", ft_atoi(" \t\v\n\r\f123"));
// 	return (0);
// }