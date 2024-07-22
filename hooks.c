/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:02:22 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 16:14:33 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_scroll_func(double xdelta, double ydelta, void *param)
{
	t_open	*data;

	data = (t_open *)param;
	(void)xdelta;
	if (ydelta > 0)
	{
		data->zoom *= 1.1;
	}
	else if (ydelta < 0)
	{
		data->zoom /= 1.1;
	}
	if (data->save == 5)
		ft_julai(data);
	else if (data->save == 1)
		ft_mandelbrot(data);
}

void	my_mlx_key(mlx_key_data_t keydata, void *param)
{
	t_open	*data;

	data = (t_open *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(data->mlx, data->image);
		mlx_close_window(data->mlx);
		exit(0);
	}
}
