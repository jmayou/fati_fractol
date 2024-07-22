/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:53:38 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 16:11:55 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_open *data, int color)
{
	data->color = data->count * color;
	if (data->count == 101)
		data->color = 0;
}

void	ft_count(t_open *data)
{
	double	tmp;

	tmp = (data->z.re * data->z.re) - (data->z.im * data->z.im) + data->c.re;
	data->z.im = (2 * data->z.re * data->z.im) + data->c.im;
	data->z.re = tmp;
}

void	ft_julai(t_open *data)
{
	data->i = (-WIDTH / 2);
	while (data->i <= WIDTH / 2)
	{
		data->j = (-HEIGHT / 2);
		while (++data->j <= (HEIGHT / 2))
		{
			data->z.re = data->i / data->zoom;
			data->z.im = data->j / data->zoom;
			data->count = 1;
			while ((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4
				&& data->count <= 100)
			{
				ft_count(data);
				data->count++;
			}
			set_color(data, 0Xfff0f0ff);
			mlx_put_pixel(data->image, (WIDTH / 2) + data->i, (HEIGHT / 2)
				- data->j, data->color);
		}
		data->i++;
	}
}

void	ft_mandelbrot(t_open *data)
{
	data->i = (-WIDTH / 2);
	while (data->i <= WIDTH / 2)
	{
		data->j = (-HEIGHT / 2);
		while (++data->j <= (HEIGHT / 2))
		{
			data->z.re = 0;
			data->z.im = 0;
			data->c.re = data->i / data->zoom;
			data->c.im = data->j / data->zoom;
			data->count = 1;
			while ((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4
				&& data->count <= 100)
			{
				ft_count(data);
				data->count++;
			}
			set_color(data, 0Xfff0f0ff);
			mlx_put_pixel(data->image, (WIDTH / 2) + data->i, (HEIGHT / 2)
				- data->j, data->color);
		}
		data->i++;
	}
}
