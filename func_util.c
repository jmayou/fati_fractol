/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:38:17 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/06 11:07:25 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

float	ft_atof(char *str)
{
	int		i;
	int		r1;
	float	r2;
	int		j;
	int		sign;

	i = 0;
	r1 = 0;
	r2 = 0;
	j = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		r1 = (r1 * 10) + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			r2 = (r2 * 10) + str[i] - '0';
			j++;
			i++;
		}
	}
	while (j > 0)
	{
		r2 = r2 / 10;
		j--;
	}
	return ((r1 + r2) * sign);
}
// int main()
// {
// 	char str[] = "-15.022";
// 	printf("%f\n",ft_atof(str));
// 	return (0);
// }