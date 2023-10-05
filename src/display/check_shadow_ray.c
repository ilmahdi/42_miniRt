/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:12:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:17:21 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_shadow_ray2(t_elements *elem, t_cogo sh_r, t_cogo o, t_close *inf)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
	{
		if (inf->object == 'D' && inf->i == i)
			continue ;
		if (!check_sh_r_cy_disk(elem, sh_r, i, o))
			return (0);
	}
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
	{
		if (inf->object == 'd' && inf->i == i)
			continue ;
		if (!check_sh_r_cy_disk(elem, sh_r, -i - 1, o))
			return (0);
	}
	return (1);
}

bool	check_shadow_ray(t_elements *elem, t_cogo sh_r, t_cogo o, t_close *inf)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (!check_sh_r_sp(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (!check_sh_r_pl(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (!check_sh_r_cy(elem, sh_r, (size_t)i, o))
			return (0);
	return (check_shadow_ray2(elem, sh_r, o, inf));
}
