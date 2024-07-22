/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:38:58 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 16:16:37 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(1, "invalide args", 12);
	exit(1);
}

void	ft_check_args(int ac, char *str[], t_open *data)
{
	if (ft_strcmp("mandelbrot", str[1]) == 0 && ac == 2)
	{
		data->save = 1;
		ft_open_wind(data);
	}
	else if (ft_strcmp("julia", str[1]) == 0 && ac == 4
		&& check_is_number(str[2]) == 1 && check_is_number(str[3]) == 1)
	{
		data->c.re = ft_atof(str[2]);
		data->c.im = ft_atof(str[3]);
		data->save = 5;
		if ((data->c.re <= 2 && data->c.re >= -2) && (data->c.im <= 2
				&& data->c.im >= -2))
		{
			ft_open_wind(data);
		}
		else
			error();
	}
	else
		error();
}

int	main(int ac, char *str[])
{
	t_open	data;

	if (ac < 2)
		error();
	else
		ft_check_args(ac, str, &data);
	return (0);
}
