/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:31 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/13 20:51:18 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_color	make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void	ft_colors(void *param)
{
	t_color		color;
	uint32_t	num_pixels;
	uint32_t	i;
	mlx_image_t	*image;

	image = (mlx_image_t *)param;
	color = make_color(255, 255, 255, 255);
	num_pixels = image->width * image->height;
	i = 0;
	while (i < num_pixels)
	{
		mlx_put_pixel(image, i % image->width, i / image->width,
			*((int32_t *)&color));
		i++;
	}
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "SO_LONG Game", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 712, 312)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == 1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_colors, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
