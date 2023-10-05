/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_A_C_L_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:12:55 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/11 10:00:33 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	check_amb_light_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.a_nbr++;
		if (strlen_2d(param) != 3)
			return (*iden = A_NBR_INFO, (void)0);
		if (check_dot(param[1], 1, 1) || check_limit(param[1], 0, 1))
			return (*iden = A_RATIO, (void)0);
		if (check_tuple(param[2], 0, 0, 0))
			return (*iden = A_RGB, (void)0);
		return ;
	}
	parse_ratio(param[1], &(elem->a[index].ratio));
	parse_tuple_rgb(param[2], &(elem->a[index].rgb));
	index++;
}

void	check_camera_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.c_nbr++;
		if (strlen_2d(param) != 4)
			return (*iden = C_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = C_COGO, (void)0);
		if (check_tuple(param[2], 1, 1, 1))
			return (*iden = C_ORIENT, (void)0);
		if (check_dot(param[3], 0, 1) || check_limit(param[3], 0, 180))
			return (*iden = C_FOV, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->c[index].pos));
	parse_tuple_cogo(param[2], &(elem->c[index].orient));
	parse_ratio(param[3], &(elem->c[index].fov));
	index++;
}

void	check_light_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.l_nbr++;
		if (strlen_2d(param) != 4)
			return (*iden = L_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = L_COGO, (void)0);
		if (check_dot(param[2], 0, 1) || check_limit(param[2], 0, 1))
			return (*iden = L_RATIO, (void)0);
		if (check_tuple(param[3], 0, 0, 0))
			return (*iden = L_RGB, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->l[index].pos));
	parse_ratio(param[2], &(elem->l[index].bright));
	parse_tuple_rgb(param[3], &(elem->l[index].rgb));
	index++;
}
