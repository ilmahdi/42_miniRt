/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone_element_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:16:55 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:31:29 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	map_invalid(char iden)
{
	ft_putendl_fd("Erorr", 2);
	if (print_error_orient_vec(iden))
		exit (1);
	if (print_error_msg_map(iden))
		exit (1);
	else if (print_error_msg_a_c(iden))
		exit (1);
	else if (print_error_msg_l_pl(iden))
		exit (1);
	else if (print_error_msg_sp_cy(iden))
		exit(1);
	else if (print_error_cone(iden))
		exit(1);
}

void	check_cone_element(t_elements *elem, char *iden, char **param)
{
	static int	index;

	if (*iden == 'x')
	{
		elem->elem_nbr.co_nbr++;
		if (strlen_2d(param) != 6)
			return (*iden = CO_NBR_INFO, (void)0);
		if (check_tuple(param[1], 2, 1, 1))
			return (*iden = CO_COGO, (void)0);
		if (check_tuple(param[2], 1, 1, 1))
			return (*iden = CO_ORIENT, (void)0);
		if (check_dot(param[3], 0, 1))
			return (*iden = CO_DIAMETER, (void)0);
		if (check_dot(param[4], 0, 1))
			return (*iden = CO_HEIGHT, (void)0);
		if (check_tuple(param[5], 0, 0, 0))
			return (*iden = CO_RGB, (void)0);
		return ;
	}
	parse_tuple_cogo(param[1], &(elem->co[index].pos));
	parse_tuple_cogo(param[2], &(elem->co[index].orient));
	parse_ratio(param[3], &(elem->co[index].base));
	parse_ratio(param[4], &(elem->co[index].hgt));
	parse_tuple_rgb(param[5], &(elem->co[index].rgb));
	index++;
}
