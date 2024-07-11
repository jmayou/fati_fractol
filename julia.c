/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:53:38 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/08 19:00:00 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_count ( open_t *data )
{
	double tmp ;
	tmp = ( data->z.re * data->z.re) - (data->z.im * data->z.im) + data->c.re ;
	data->z.im =  2 * ( data->z.re * data->z.im) + data->c.im;
	data->z.re = tmp;
	// printf("[%f]\n",data->z.im);
	// printf ("[%f]\n",data->z.re);
	// exit(1);
}

void ft_julai( open_t *data )
{

	int count = 0;
	data->i = (-WIDTH / 2) ;
	// printf("%d",data->i);

	while ( data->i < WIDTH - 1)
	{	
		data->z.re = data->i;
		data->j = (- HEIGHT / 2);
		// printf("%d",data->j);
		// exit(1);
		data->z.im  = data->j;

		while ( data->j < (HEIGHT - 1))
		{
			count = 0;
			while ( (data->z.re * data->z.re ) * (data->z.im * data->z.im) <= 4 && count < 10)
			{
				ft_count( data);
				count++;
			}
			printf("----->%d\n",data->j);
			printf("------>%d\n",data->i);
			if ( count != 100)
			{
				mlx_put_pixel(data->image,(WIDTH / 2) - data->i,(HEIGHT / 2) + data->j ,0xFF0000FF);	
			}
			
			data->j++;
		}

		data->i++;
	} 
}


