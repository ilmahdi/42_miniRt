/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cogo_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:08:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 10:02:01 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	update_cogo_element(t_cogo *element, double **m_pos)
{
	t_cogo	hol;

	hol = *element;
	element->x = (m_pos[0][0] * hol.x) + (m_pos[0][1] * hol.y)
		+ (m_pos[0][2] * hol.z) + (m_pos[0][3]);
	element->y = (m_pos[1][0] * hol.x) + (m_pos[1][1] * hol.y)
		+ (m_pos[1][2] * hol.z) + (m_pos[1][3]);
	element->z = (m_pos[2][0] * hol.x) + (m_pos[2][1] * hol.y)
		+ (m_pos[2][2] * hol.z) + (m_pos[2][3]);
}	

void	update_orient_element(t_cogo *element, double **m_pos)
{
	t_cogo	o;

	o = *element;
	update_cogo_element(&o, m_pos);
	element->x = o.x - m_pos[0][3];
	element->y = o.y - m_pos[1][3];
	element->z = o.z - m_pos[2][3];
}

void	update_cogo_2(t_elements *elem, double **m_pos)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
	{
		update_cogo_element(&(elem->cy[i].pos), m_pos);
		update_orient_element(&(elem->cy[i].orient), m_pos);
	}
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
	{
		update_cogo_element(&(elem->co[i].pos), m_pos);
		update_orient_element(&(elem->co[i].orient), m_pos);
	}
	update_orient_element(&(elem->c->orient), m_pos);
	update_cogo_element(&(elem->c->pos), m_pos);
}

void	update_cogo(t_elements *elem, double **m_pos)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
		update_cogo_element(&(elem->l[i].pos), m_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		update_cogo_element(&(elem->sp[i].pos), m_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
	{
		update_cogo_element(&(elem->pl[i].pos), m_pos);
		update_orient_element(&(elem->pl[i].orient), m_pos);
	}
	update_cogo_2(elem, m_pos);
}

double	**get_transf_matrix(t_cogo v_orient, t_cogo v_pos)
{
	double	**t_pos_y;
	double	**t_pos_x;
	double	**t_pos;
	double	**m_pos;

	t_pos = NULL;
	m_pos = NULL;
	t_pos_y = NULL;
	t_pos_x = NULL;
	t_pos = alloc_matrix(t_pos, 4);
	m_pos = alloc_matrix(m_pos, 4);
	t_pos_y = alloc_matrix(t_pos_y, 4);
	t_pos_x = alloc_matrix(t_pos_x, 4);
	fill_sub_matrix(v_orient, t_pos_y, t_pos_x);
	fill_main_matrix(t_pos, t_pos_y, t_pos_x);
	t_pos[0][3] = v_pos.x;
	t_pos[1][3] = v_pos.y;
	t_pos[2][3] = v_pos.z;
	inverse_matrix(m_pos, t_pos, 4);
	free_matrix(t_pos_y, 4);
	free_matrix(t_pos_x, 4);
	free_matrix(t_pos, 4);
	return (m_pos);
}
