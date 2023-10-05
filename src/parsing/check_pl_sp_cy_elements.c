/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pl_sp_cy_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:12:46 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 08:29:37 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	check_plane_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.pl_nbr++;
		if (strlen_2d(param) != 4)
			return (*iden = PL_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = PL_COGO, (void)0);
		if (check_tuple(param[2], 1, 1, 1))
			return (*iden = PL_ORIENT, (void)0);
		if (check_tuple(param[3], 0, 0, 0))
			return (*iden = PL_RGB, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->pl[index].pos));
	parse_tuple_cogo(param[2], &(elem->pl[index].orient));
	parse_tuple_rgb(param[3], &(elem->pl[index].rgb));
	index++;
}

void	check_sphere_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.sp_nbr++;
		if (strlen_2d(param) != 4)
			return (*iden = SP_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = SP_COGO, (void)0);
		if (check_dot(param[2], 0, 1))
			return (*iden = SP_DIAMETER, (void)0);
		if (check_tuple(param[3], 0, 0, 0))
			return (*iden = SP_RGB, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->sp[index].pos));
	parse_ratio(param[2], &(elem->sp[index].diameter));
	parse_tuple_rgb(param[3], &(elem->sp[index].rgb));
	index++;
}

void	check_cylinder_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.cy_nbr++;
		if (strlen_2d(param) != 6)
			return (*iden = CY_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = CY_COGO, (void)0);
		if (check_tuple(param[2], 1, 1, 1))
			return (*iden = CY_ORIENT, (void)0);
		if (check_dot(param[3], 0, 1))
			return (*iden = CY_DIAMETER, (void)0);
		if (check_dot(param[4], 0, 1))
			return (*iden = CY_HEIGHT, (void)0);
		if (check_tuple(param[5], 0, 0, 0))
			return (*iden = CY_RGB, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->cy[index].pos));
	parse_tuple_cogo(param[2], &(elem->cy[index].orient));
	parse_ratio(param[3], &(elem->cy[index].diameter));
	parse_ratio(param[4], &(elem->cy[index].height));
	parse_tuple_rgb(param[5], &(elem->cy[index].rgb));
	index++;
}
