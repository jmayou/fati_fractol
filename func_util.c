/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:38:17 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 13:44:17 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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

int	check_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] == '.' && i != 0 && str[i + 1] != '\0')
	{
		i++;
	}
	while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

void	ft_fill(t_atof *var)
{
	var->i = 0;
	var->n1 = 0;
	var->n2 = 0;
	var->sing = 1;
	var->k = 1;
}

float	ft_atof(char *str)
{
	t_atof	var;

	ft_fill(&var);
	if (str[var.i] == '-' || str[var.i] == '+')
	{
		if (str[var.i] == '-')
			var.sing = -1;
		var.i++;
	}
	while (str[var.i] && str[var.i] >= '0' && str[var.i] <= '9')
	{
		var.n1 = (var.n1 * 10) + (str[var.i] - '0');
		var.i++;
	}
	if (str[var.i] == '.')
	{
		while (str[++var.i] && str[var.i] >= '0' && str[var.i] <= '9')
		{
			var.n2 = (var.n2 * 10) + (str[var.i] - '0');
			var.k++;
		}
	}
	while (--var.k > 0)
		var.n2 = var.n2 / 10;
	return ((var.n1 + var.n2) * var.sing);
}
