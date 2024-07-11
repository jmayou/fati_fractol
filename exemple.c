/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:27:20 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/08 13:21:05 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# define WIDTH 800
# define HEIGHT 600

void	ft_complexe(t_complexe *z, t_complexe c)
{
	double	tmp;

	tmp = (z->re * z->re) - (z->im * z->im) + c.re;
	z->im = (2 * z->re * z->im) + c.im;
	z->re = tmp;
}

void	julia(t_data *data)
{
	data->i = (-WIDTH / 2);
	while (data->i <= WIDTH / 2)
	{
		data->j = -HEIGHT / 2;
		while (++data->j <= HEIGHT / 2)
		{
			data->z.re = data->i / data->zoom;
			data->z.im = data->j / data->zoom;
			data->fin = 1;
			while ((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4
				&& data->fin < 100)
			{
				ft_complexe(&data->z, data->c);
				data->fin++;
			}
		}
		data->i++;
	}
}
