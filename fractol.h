/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:02:52 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 15:54:27 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 600
# define BLUE 0Xfff0f0

typedef struct s_atof
{
	int			i;
	int			sing;
	int			n1;
	float		n2;
	int			k;
}				t_atof;

typedef struct s_complx
{
	double		re;
	double		im;

}				t_complx;

typedef struct s_open
{
	int			save;
	double		color;
	int			count;
	double		zoom;
	int			i;
	int			j;
	mlx_t		*mlx;

	mlx_image_t	*image;
	t_complx	z;
	t_complx	c;

}				t_open;

void			mlx_scroll_func(double xdelta, double ydelta, void *param);
void			ft_open_wind(t_open *data);
void			ft_count(t_open *data);
void			ft_check_args(int ac, char *str[], t_open *data);
int				ft_strcmp(char *s1, char *s2);
float			ft_atof(char *str);
int				check_is_number(char *str);
int				ft_strlen(char *str);
void			ft_julai(t_open *data);
void			ft_mandelbrot(t_open *data);
void			my_mlx_key(mlx_key_data_t keydata, void *param);

#endif
