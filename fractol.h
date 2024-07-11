/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:02:52 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/08 17:00:22 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 600
# define JUL 0
#define MAN	1

typedef struct complx_s
{
	double re;
	double  im;

} complx_t;


typedef struct open_s
{
	int 	i ;
	int 	j;
	mlx_t *mlx;

	mlx_image_t *image;	
	complx_t z ;
	complx_t c;

} open_t;


void ft_open_wind( open_t *data , int i , char *str);
void ft_count ( open_t *data );
void	ft_check_args(int ac , char *str[] ,open_t *data);
int	ft_strcmp( char *s1,  char *s2);
float	ft_atof(char *str);
int	check_is_number(char *str);
int ft_strlen(char *str);
void ft_julai( open_t *data );


#endif