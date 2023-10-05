/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disks_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:25:54 by obeaj             #+#    #+#             */
/*   Updated: 2022/06/19 16:26:01 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	disk_cy_inter(t_elements *elem, t_cogo ray, int i, t_cogo o)
{
	t_cogo	disk;
	t_cogo	c_p;
	double	t;

	disk = (t_cogo){};
	if (i < 0)
	{
		i = -i - 1;
		disk.z = -elem->cy[i].height / 2;
	}
	else
		disk.z = elem->cy[i].height / 2;
	update_orient_element(&ray, elem->cy[i].m_pos);
	update_cogo_element(&o, elem->cy[i].m_pos);
	add_sub_vectors(&c_p, disk, o, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + o.x, 2) + pow((t * ray.y) + o.y, 2) \
			< pow(elem->cy[i].diameter / 2, 2))
		return (t);
	return (-1);
}

double	disk_co_inter(t_elements *elem, t_cogo ray, size_t index, t_cogo o)
{
	t_cogo	disk;
	t_cogo	c_p;
	double	t;

	disk = (t_cogo){};
	disk.z = elem->co[index].hgt;
	update_orient_element(&ray, elem->co[index].m_pos);
	update_cogo_element(&o, elem->co[index].m_pos);
	add_sub_vectors(&c_p, disk, o, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + o.x, 2) + pow((t * ray.y) + o.y, 2) \
			<= pow(elem->co[index].base / 2, 2))
		return (t);
	return (-1);
}
