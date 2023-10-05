/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_epsilon_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:58:16 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 15:58:40 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	epsilon_cone(t_elements *elem, size_t i)
{
	double	cof;
	t_cogo	o_c;
	t_cogo	o_l;
	t_cogo	o;

	o = elem->co[i].orient;
	cof = cos(atan((elem->co[i].base / 2) / elem->co[i].hgt));
	add_sub_vectors(&o_c, elem->c->pos, elem->co[i].pos, -1);
	add_sub_vectors(&o_l, elem->l->pos, elem->co[i].pos, -1);
	resize_vec(&o_c, o_c, 1);
	resize_vec(&o_l, o_l, 1);
	resize_vec(&o, o, 1);
	if ((dot(o_c, o) < cof && dot(o_l, o) < cof \
	&& mag_vector(o_l) < elem->co[i].hgt \
	&& mag_vector(o_l) < elem->co[i].hgt) \
	|| (dot(o_c, o) > cof && dot(o_l, o) > cof))
		return (1);
	return (0);
}

double	epsilon_co_disk(t_elements *elem, size_t index, t_cogo o)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, o, -1);
	add_sub_vectors(&l_c, elem->l->pos, o, -1);
	if ((dot(c_c, elem->co[index].orient) * \
				dot(l_c, elem->co[index].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}
