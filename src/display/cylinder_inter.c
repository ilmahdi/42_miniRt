/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:19:30 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/13 12:12:25 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	cylinder_inter(t_elements *elem, t_cogo ray, size_t i)
{
	double	delta;
	double	t;

	t = 0;
	update_orient_element(&ray, elem->cy[i].m_pos);
	delta = pow(2 * dot_2d(ray, elem->cy[i].o_c), 2) - (4 * dot_2d(ray, ray)
			* (dot_2d(elem->cy[i].o_c, elem->cy[i].o_c) - \
				pow(elem->cy[i].diameter / 2, 2)));
	if (delta > 0)
	{
		if (mag_vector_2d(elem->cy[i].o_c) >= (elem->cy[i].diameter / 2))
		{
			t = ((-2 * dot_2d(ray, elem->cy[i].o_c)) - sqrt(delta)) / \
				(2 * dot_2d(ray, ray));
			if (fabs((t * ray.z) + elem->cy[i].z_o) < (elem->cy[i].height / 2))
				return (t);
			return (-1);
		}
		t = ((-2 * dot_2d(ray, elem->cy[i].o_c)) + sqrt(delta)) / \
			(2 * dot_2d(ray, ray));
		if (fabs((t * ray.z) + elem->cy[i].z_o) < (elem->cy[i].height / 2))
			return (t);
	}
	return (-1);
}

double	cylinder_inter_sh(t_elements *elem, t_cogo ray, size_t i, t_cogo o)
{
	t_cogo	p_c;
	t_cogo	null;
	double	delta;
	double	t;

	t = 0;
	null = (t_cogo){};
	update_orient_element(&ray, elem->cy[i].m_pos);
	update_cogo_element(&o, elem->cy[i].m_pos);
	add_sub_vectors_2d(&p_c, o, null, -1);
	delta = pow(2 * dot_2d(ray, p_c), 2) - (4 * dot_2d(ray, ray)
			* (dot_2d(p_c, p_c) - pow(elem->cy[i].diameter / 2, 2)));
	if (delta > 0)
	{
		t = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
		if (fabs((t * ray.z) + o.z) < (elem->cy[i].height / 2))
			if (t > 0.000001 && t < 1)
				return (t);
		t = ((-2 * dot_2d(ray, p_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
		if (fabs((t * ray.z) + o.z) < (elem->cy[i].height / 2))
			if (t > 0.000001 && t < 1)
				return (t);
	}
	return (-1);
}
