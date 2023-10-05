/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_optimised.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 15:45:47 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	recursion_condition(t_elements *elem,
		t_cogo ray, double p_stp, bool depth)
{
	t_rgb	color;

	if (depth)
		color = get_pixel_color(elem, ray, p_stp / 2, 0);
	else
		color = check_inter(elem, ray);
	return (color);
}

t_rgb	get_pixel_color(t_elements *elem, t_cogo ray, double p_stp, bool depth)
{
	t_rgb	color;
	t_rgb	color_h;

	ray.x -= (p_stp) / 4;
	ray.y += (p_stp) / 4;
	color = recursion_condition(elem, ray, p_stp, depth);
	ray.x += (p_stp) / 2;
	color_h = recursion_condition(elem, ray, p_stp, depth);
	color = mean_rgb(color, color_h);
	ray.x -= (p_stp) / 2;
	ray.y -= (p_stp) / 2;
	color_h = recursion_condition(elem, ray, p_stp, depth);
	color = mean_rgb(color, color_h);
	ray.x += (p_stp) / 2;
	color_h = recursion_condition(elem, ray, p_stp, depth);
	color = mean_rgb(color, color_h);
	return (color);
}
