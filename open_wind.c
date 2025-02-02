/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:07:00 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 15:24:31 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_open_wind(t_open *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	data->zoom = 250.0;
	if (data->save == 5)
		ft_julai(data);
	else if (data->save == 1)
		ft_mandelbrot(data);
	mlx_scroll_hook(data->mlx, mlx_scroll_func, data);
	mlx_key_hook(data->mlx, my_mlx_key, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->image);
	mlx_close_window(data->mlx);
}
