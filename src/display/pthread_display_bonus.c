/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_display_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:02:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:02:16 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef struct s_var
{
	int		x;
	int		y;
	int		line;
	double	p_stp;
	double	x_ray_h;
}	t_var;

void	*pthread_display(void *pinfo_ptr)
{
	t_var		var;
	t_cogo		ray;
	t_pth_ptr	*pinfo;

	var.y = -1;
	pinfo = pinfo_ptr;
	var.line = pinfo->line;
	init_ray(pinfo->elem, &ray);
	var.p_stp = fabs(ray.x * 2) / 1000;
	var.x_ray_h = ray.x;
	ray.y -= var.line * var.p_stp;
	while (++var.y < 100)
	{
		var.x = -1;
		ray.x = var.x_ray_h;
		while (++var.x < 1000)
		{
			ray.x += var.p_stp;
			fill_color_buffer(pinfo->gfx, \
			get_pixel_color(pinfo->elem, ray, var.p_stp, 1), var.x, var.line);
		}
		ray.y -= var.p_stp;
		var.line++;
	}
	return (NULL);
}

void	create_thrads(t_elements *elem, t_mlx_ptr *gfx)
{
	pthread_t	pth[10];
	t_pth_ptr	pinfo;
	int			i;

	pinfo.elem = elem;
	pinfo.gfx = gfx;
	i = -1;
	while (++i < 10)
	{
		pinfo.line = 100 * i;
		pthread_create(&pth[i], NULL, pthread_display, (void *)&pinfo);
		usleep(100);
	}
	i = -1;
	while (++i < 10)
		pthread_join(pth[i], NULL);
}
