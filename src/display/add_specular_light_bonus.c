/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_specular_light_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:32 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:00:35 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	add_specular_light_cy(t_elements *elem, t_cogo wi, size_t i, t_cogo o)
{
	t_rgb	rgb_s;
	t_cogo	p_c;
	t_cogo	wo;
	t_cogo	n;

	add_sub_vectors(&wo, elem->c->pos, o, -1);
	resize_vec(&wo, wo, 1);
	add_sub_vectors(&p_c, elem->cy[i].pos, o, -1);
	resize_vec(&p_c, p_c, 1);
	scaler_multiplication(&n, elem->cy[i].orient, dot(elem->cy[i].orient, p_c));
	add_sub_vectors(&n, n, p_c, -1);
	resize_vec(&wi, wi, 1);
	resize_vec(&n, n, 1);
	rgb_s = add_specular_light(elem, wi, n, wo);
	return (rgb_s);
}

t_rgb	add_specular_light(t_elements *elem, t_cogo wi, t_cogo n, t_cogo wo)
{
	t_rgb	s_rgb;
	t_cogo	r;

	r = (t_cogo){};
	s_rgb = (t_rgb){};
	scaler_multiplication(&r, n, (2 * dot(n, wi)));
	add_sub_vectors(&r, r, wi, -1);
	resize_vec(&wo, wo, 1);
	if (dot(r, wo) > 0)
		s_rgb = multi_rgb(elem->l->rgb, \
				elem->l->rgb, pow(dot(r, wo), 50) * elem->l->bright * 0.5);
	return (s_rgb);
}
