/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:59:59 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/07/22 14:00:05 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (data->count == 100)
				mlx_put_pixel(data->image, (WIDTH / 2) + data->i, (HEIGHT / 2)
					- data->j, 0xFF0000);
			else
				mlx_put_pixel(data->image, (WIDTH / 2) + data->i, (HEIGHT / 2)
					- data->j, 0x0000FF * data->count);