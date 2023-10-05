/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:01:56 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 11:25:18 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	label_statement(size_t c)
{
	if (c > 255)
		return (255);
	return (c);
}

t_rgb	multi_rgb(t_rgb rgb1, t_rgb rgb2, double ratio)
{
	t_rgb	r_rgb;

	r_rgb.r = rgb1.r * (rgb2.r / 255) * ratio;
	r_rgb.g = rgb1.g * (rgb2.g / 255) * ratio;
	r_rgb.b = rgb1.b * (rgb2.b / 255) * ratio;
	return (r_rgb);
}

t_rgb	add_rgb(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	r_rgb;
	size_t	b;
	size_t	g;
	size_t	r;

	r = rgb1.r + rgb2.r;
	g = rgb1.g + rgb2.g;
	b = rgb1.b + rgb2.b;
	r_rgb.r = label_statement(r);
	r_rgb.g = label_statement(g);
	r_rgb.b = label_statement(b);
	return (r_rgb);
}

t_rgb	mean_rgb(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	r_rgb;

	r_rgb.r = (rgb1.r + rgb2.r) / 2;
	r_rgb.g = (rgb1.g + rgb2.g) / 2;
	r_rgb.b = (rgb1.b + rgb2.b) / 2;
	return (r_rgb);
}
