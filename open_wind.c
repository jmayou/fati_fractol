/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:07:00 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/08 16:19:36 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	void ft_open_wind( open_t *data , int i , char *str)
	{
		// int i = 0;
		// int j = 0;
		// open_t *init  = NULL;
		// open_t *img = NULL ;
		// mlx_t *mlx = NULL;
		// mlx_image_t *img = NULL;
		// init = (open_t *)malloc(sizeof(open_t *));
		// img = (open_t *)malloc(sizeof(open_t *));
		data->mlx = mlx_init( WIDTH , HEIGHT , "fractol",false );
		data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx,data->image, 0 , 0);
		if ( i == 0  )
			ft_julai(data);

		// while (i < HEIGHT / 2 )
		// {
		// 	j = 0;
		// 	while ( j <  WIDTH / 2)
		// 	{
		// 		mlx_put_pixel(data->image,j,i ,0xFF0000FF);
		// 		j++;
		// 	}
		// 	i++;
		// }
		// mlx_put_pixel(img->image,0,0 ,0xFF0000FF);
		mlx_loop(data->mlx);
		
	}
	
