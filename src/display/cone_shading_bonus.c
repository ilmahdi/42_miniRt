/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_shading_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:34:41 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 16:07:35 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	cone_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	n;
	t_cogo	oc;
	t_cogo	wo;
	t_cogo	p_c;
	t_rgb	rgb_h;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->co[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && epsilon_cone(elem, info->i) \
	&& check_shadow_ray(elem, sh_r, o, info))
	{
		add_sub_vectors(&p_c, o, elem->co[info->i].pos, -1);
		resize_vec(&p_c, p_c, 1);
		resize_vec(&oc, elem->co[info->i].orient, 1);
		scaler_multiplication(&p_c, p_c, dot(oc, p_c));
		add_sub_vectors(&n, p_c, oc, -1);
		resize_vec(&n, n, 1);
		resize_vec(&sh_r, sh_r, 1);
		rgb_h = add_rgb(multi_rgb(elem->co[info->i].rgb, elem->l->rgb, \
					(fabs(dot(sh_r, n))) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, o, -1);
		return (add_rgb(add_specular_light(elem, sh_r, n, wo), rgb_h));
	}
	return (rgb_h);
}

t_rgb	disk_co_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	wo;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->co[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_r, o, info))
	{
		resize_vec(&sh_r, sh_r, 1);
		resize_vec(&elem->co[info->i].orient, elem->co[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->co[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_r, elem->co[info->i].orient)) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, o, -1);
		rgb_s = add_specular_light(elem, sh_r, elem->co[info->i].orient, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

bool	check_sh_r_co(t_elements *elem, t_cogo sh_r, size_t i, t_cogo o)
{
	double	t_hol;

	t_hol = cone_inter_sh(elem, sh_r, i, o);
	if (t_hol > 0)
		return (0);
	return (1);
}

bool	check_sh_r_co_disk(t_elements *elem, t_cogo sh_r, size_t i, t_cogo o)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_co_disk(elem, i, o);
	t_hol = disk_co_inter(elem, sh_r, i, o);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}
