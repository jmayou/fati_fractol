/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:38:58 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/08 16:20:31 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
 
 
int	check_is_number(char *str)
{
	int i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1]  != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9'  && str[i] != '.')
	{
		i++;
	}
	if (str[i] == '.' && i != 0 && str[i + 1] != '\0')
	{
		
		i++;
	}
	while ( (str [i] != '\0' && str[i] >= '0' &&  str[i] <= '9'))
	{
		i++;
	}
	
	if (i == ft_strlen(str))
	{
		return(1);
	}
	else
	{
		return (0);
	}
}

void	ft_check_args(int ac , char *str[] ,open_t *data)
{
	
	if ( ac < 2)
	{
		write(1,"invalide args",12);
		exit(1);
	}
	else if ( ft_strcmp("mandelbrot",str[1]) == 0 && ac == 2)
	{
		
	}
	else if ( ft_strcmp("julia",str[1]) == 0 && ac == 4  && check_is_number(str[2]) == 1 && check_is_number(str[3]) == 1)
	{
		data->c.re = ft_atof(str[2]);
		data->c.im= ft_atof(str[3]);
		ft_open_wind( data , JUL , str[1]);
			
	}
	else 
	{
		write(1,"invalide args",12);
		exit(1);
	}
		
}
 
int main(int ac , char *str[])
{
	open_t data;
	
	ft_check_args(ac , str , &data);
	// ft_open_wind( &data);
	// printf("loool\n");
}
