/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_shading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:49 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 14:16:40 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	sphere_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	wo;
	t_cogo	p_c;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->sp[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_r, o, info))
	{
		resize_vec(&sh_r, sh_r, 1);
		add_sub_vectors(&p_c, o, elem->sp[info->i].pos, -1);
		resize_vec(&p_c, p_c, 1);
		rgb_h = add_rgb(multi_rgb(elem->sp[info->i].rgb, elem->l->rgb, \
					fabs(dot(sh_r, p_c) * elem->l->bright)), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, o, -1);
		rgb_s = add_specular_light(elem, sh_r, p_c, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	plane_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	wo;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->pl[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_r, o, info))
	{
		resize_vec(&sh_r, sh_r, 1);
		resize_vec(&elem->pl[info->i].orient, elem->pl[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->pl[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_r, elem->pl[info->i].orient)) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, o, -1);
		rgb_s = add_specular_light(elem, sh_r, elem->pl[info->i].orient, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	cylinder_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	p_c;
	t_cogo	pos_cy;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	pos_cy = (t_cogo){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && epsilon_cylinder(elem, info->i) \
	&& check_shadow_ray(elem, sh_r, o, info))
	{
		rgb_s = add_specular_light_cy(elem, sh_r, info->i, o);
		update_cogo_element(&o, elem->cy[info->i].m_pos);
		update_orient_element(&sh_r, elem->cy[info->i].m_pos);
		add_sub_vectors_2d(&p_c, o, pos_cy, -1);
		resize_vec_2d(&p_c, p_c, 1);
		resize_vec_2d(&sh_r, sh_r, 1);
		rgb_h = add_rgb(multi_rgb(elem->cy[info->i].rgb, elem->l->rgb, \
					(fabs(dot_2d(sh_r, p_c))) * elem->l->bright), rgb_h);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	disk_cy_shading(t_elements *elem, t_close *info, t_cogo sh_r, t_cogo o)
{
	t_cogo	wo;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && epsilon_cy_disk(elem, info->i, o) \
	&& check_shadow_ray(elem, sh_r, o, info))
	{
		resize_vec(&sh_r, sh_r, 1);
		resize_vec(&elem->cy[info->i].orient, elem->cy[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->cy[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_r, elem->cy[info->i].orient)) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, o, -1);
		rgb_s = add_specular_light(elem, sh_r, elem->cy[info->i].orient, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}
