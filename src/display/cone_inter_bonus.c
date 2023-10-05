/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:01:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:01:15 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	cone_inter(t_elements *elem, t_cogo ray, size_t i)
{
	const double	m = pow(elem->co[i].base / 2, 2) / pow(elem->co[i].hgt, 2);
	const t_cogo	o = elem->co[i].m_o;
	t_cogo			o_c;
	t_eq_comp		eq;

	o_c = elem->co[i].o_c;
	update_orient_element(&ray, elem->co[i].m_pos);
	eq.a = dot(ray, ray) - (m * pow(dot(ray, o), 2)) - pow((dot(ray, o)), 2);
	eq.b = 2 * (dot(ray, o_c) - (m * dot(ray, o) * dot(o_c, o)) - \
			(dot(ray, o) * dot(o_c, o)));
	eq.c = dot(o_c, o_c) - (m * pow(dot(o_c, o), 2)) - pow(dot(o_c, o), 2);
	eq.delta = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.delta >= 0)
	{
		resize_vec(&o_c, o_c, 1);
		if (dot(o_c, o) < cos(atan((elem->co[i].base / 2) / elem->co[i].hgt)))
			eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
		else
			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
		scaler_multiplication(&ray, ray, eq.t);
		add_sub_vectors(&ray, ray, elem->co[i].m_p, 1);
		if ((dot(ray, o) > 0 && fabs(ray.z) < (elem->co[i].hgt)) || !ray.z)
			return (eq.t);
	}
	return (-1);
}

double	cone_solution(t_eq_comp eq, t_cogo ray, t_cogo osh, t_elements *elem)
{
	if (eq.i < 0)
	{
		eq.i = -eq.i - 1;
		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
	}
	else
		eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
	scaler_multiplication(&ray, ray, eq.t);
	add_sub_vectors(&ray, ray, osh, 1);
	if ((dot(ray, elem->co[eq.i].m_o) > 0 \
	&& fabs(ray.z) < elem->co[eq.i].hgt) || !ray.z)
		return (eq.t);
	return (-1);
}

double	cone_inter_sh(t_elements *elem, t_cogo ray, size_t i, t_cogo osh)
{
	const double	m = pow(elem->co[i].base / 2, 2) / pow(elem->co[i].hgt, 2);
	const t_cogo	o = elem->co[i].m_o;
	t_cogo			o_c;
	t_eq_comp		eq;

	update_orient_element(&ray, elem->co[i].m_pos);
	update_cogo_element(&osh, elem->co[i].m_pos);
	add_sub_vectors(&o_c, osh, (t_cogo){}, -1);
	eq.a = dot(ray, ray) - (m * pow(dot(ray, o), 2)) - pow((dot(ray, o)), 2);
	eq.b = 2 * (dot(ray, o_c) - (m * dot(ray, o) * dot(o_c, o)) - \
			(dot(ray, o) * dot(o_c, o)));
	eq.c = dot(o_c, o_c) - (m * pow(dot(o_c, o), 2)) - pow(dot(o_c, o), 2);
	eq.delta = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.delta > 0)
	{
		eq.i = i;
		eq.t = cone_solution(eq, ray, osh, elem);
		if (eq.t > 0.00000001 && eq.t < 1)
			return (eq.t);
		eq.i = -i - 1;
		eq.t = cone_solution(eq, ray, osh, elem);
		if (eq.t > 0.00000001 && eq.t < 1)
			return (eq.t);
	}
	return (-1);
}
