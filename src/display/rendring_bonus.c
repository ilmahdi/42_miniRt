/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:36:46 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 12:18:52 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_m_pos_cone(t_elements *elem, t_cogo o)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
	{
		elem->co[i].m_pos = get_transf_matrix(elem->co[i].orient, \
				elem->co[i].pos);
		resize_vec(&elem->co[i].m_o, elem->co[i].orient, 1);
		update_orient_element(&elem->co[i].m_o, elem->co[i].m_pos);
		add_sub_vectors(&elem->co[i].o_c, o, elem->co[i].pos, -1);
		update_orient_element(&elem->co[i].o_c, elem->co[i].m_pos);
		elem->co[i].m_p = (t_cogo){};
		update_cogo_element(&elem->co[i].m_p, elem->co[i].m_pos);
	}
}

void	fill_color_buffer(t_mlx_ptr *gfx, t_rgb color, int x, int y)
{
	t_rgb	buf_color;

	buf_color.b = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0];
	buf_color.g = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1];
	buf_color.r = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2];
	color = add_rgb(buf_color, color);
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0] = color.b;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1] = color.g;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2] = color.r;
}

void	call_display_function(t_elements *elem, t_mlx_ptr *gfx)
{
	int		i;
	t_light	*l_hol;

	i = 0;
	l_hol = elem->l;
	fill_t_buf_i(&gfx->i, gfx->endn);
	fill_position_matrix(elem);
	fill_m_pos_cone(elem, (t_cogo){});
	create_thrads(elem, gfx);
	if (elem->a)
		elem->a->single = 1;
	(elem->l)++;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
	{
		create_thrads(elem, gfx);
		(elem->l)++;
	}
	elem->l = l_hol;
}
