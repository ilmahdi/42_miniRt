/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:11:34 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 16:11:48 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_sh_r_sp(t_elements *elem, t_cogo sh_r, size_t index, t_cogo o)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_sphere(elem, index);
	if (!epsilon)
		return (0);
	t_hol = sphere_inter_sh(elem, sh_r, index, o);
	if (t_hol > epsilon)
		return (0);
	return (1);
}

bool	check_sh_r_pl(t_elements *elem, t_cogo sh_r, size_t index, t_cogo o)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_plane(elem, index, o);
	t_hol = plane_inter(elem, sh_r, index, o);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

bool	check_sh_r_cy(t_elements *elem, t_cogo sh_r, size_t index, t_cogo o)
{
	double	t_hol;

	t_hol = cylinder_inter_sh(elem, sh_r, index, o);
	if (t_hol > 0)
		return (0);
	return (1);
}

bool	check_sh_r_cy_disk(t_elements *elem, t_cogo sh_r, size_t i, t_cogo o)
{
	double	t_hol;

	t_hol = disk_cy_inter(elem, sh_r, i, o);
	if (t_hol > 0 && t_hol < 1)
		return (0);
	return (1);
}
