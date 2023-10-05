/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:14:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/13 15:13:41 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	check_element(t_elements *elem, char *element, char iden)
{
	char	**param;

	param = ft_split(element, ' ');
	if (!ft_strncmp(param[0], "A\0", 2))
		check_amb_light_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "C\0", 2))
		check_camera_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "L\0", 2))
		check_light_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "pl\0", 3))
		check_plane_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "sp\0", 3))
		check_sphere_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "cy\0", 3))
		check_cylinder_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "co\0", 3))
		check_cone_element(elem, &iden, param);
	else if (param[0])
		return (free_2d(param), '4');
	free_2d(param);
	return (iden);
}
