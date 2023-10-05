/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_epsilon_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:05:26 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 07:42:10 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	epsilon_sphere(t_elements *elem, size_t i)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->sp[i].pos, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->sp[i].pos, -1);
	if ((mag_vector(c_c) > (elem->sp[i].diameter / 2) \
				&& mag_vector(l_c) > (elem->sp[i].diameter / 2))
		|| (mag_vector(c_c) < (elem->sp[i].diameter / 2) \
				&& mag_vector(l_c) < (elem->sp[i].diameter / 2)))
		return (0.00001);
	return (0);
}

double	epsilon_plane(t_elements *elem, size_t i, t_cogo o)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, o, -1);
	add_sub_vectors(&l_c, elem->l->pos, o, -1);
	if ((dot(c_c, elem->pl[i].orient) * \
				dot(l_c, elem->pl[i].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}

double	epsilon_cylinder(t_elements *elem, size_t i)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->cy[i].pos, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->cy[i].pos, -1);
	update_orient_element(&c_c, elem->cy[i].m_pos);
	update_orient_element(&l_c, elem->cy[i].m_pos);
	if ((mag_vector_2d(c_c) < (elem->cy[i].diameter / 2) \
		&& mag_vector_2d(l_c) < (elem->cy[i].diameter / 2) \
		&& fabs(l_c.z) < elem->cy[i].height / 2 \
		&& fabs(c_c.z) < elem->cy[i].height / 2)
		|| (mag_vector_2d(c_c) > (elem->cy[i].diameter / 2) \
		&& mag_vector_2d(l_c) > (elem->cy[i].diameter / 2)))
		return (1);
	return (0);
}

double	epsilon_cy_disk(t_elements *elem, size_t i, t_cogo o)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, o, -1);
	add_sub_vectors(&l_c, elem->l->pos, o, -1);
	if ((dot(c_c, elem->cy[i].orient) * \
				dot(l_c, elem->cy[i].orient)) >= 0)
		return (1);
	return (0);
}
