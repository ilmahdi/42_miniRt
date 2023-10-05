/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:56 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 08:29:48 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	print_error_msg_map(char iden)
{
	if (iden == INVALID_EXTENSION)
		return (ft_putendl_fd("Invalid map extension (.rt)!", 2), 1);
	else if (iden == EMPTY_MAP)
		return (ft_putendl_fd("empty map!", 2), 1);
	else if (iden == INVALID_N_ARGS)
		return (ft_putendl_fd("Invalid number of arguments!", 2), 1);
	else if (iden == INVALID_ELEM)
		return (ft_putendl_fd("Invalid element in the map!", 2), 1);
	return (0);
}

bool	print_error_msg_a_c(char iden)
{
	if (iden == A_NBR_INFO)
		return (ft_putendl_fd("A : Invalid informations number!", 2), 1);
	else if (iden == A_RATIO)
		return (ft_putendl_fd("A : Invalid ratio format!", 2), 1);
	else if (iden == A_RGB)
		return (ft_putendl_fd("A : Invalid RGB format!", 2), 1);
	else if (iden == C_NBR_INFO)
		return (ft_putendl_fd("C : Invalid informations number!", 2), 1);
	else if (iden == C_COGO)
		return (ft_putendl_fd("C : Invalid coordinates format!", 2), 1);
	else if (iden == C_ORIENT)
		return (ft_putendl_fd("C : Invalid orientation vector format!", 2), 1);
	else if (iden == C_FOV)
		return (ft_putendl_fd("C : Invalid FOV format!", 2), 1);
	else if (iden == C_NOT_FOUND)
		return (ft_putendl_fd("C : Camera not found in the map!", 2), 1);
	else if (iden == A_DOUBLE)
		return (ft_putendl_fd("A : double element!", 2), 1);
	else if (iden == C_DOUBLE)
		return (ft_putendl_fd("C : double element!", 2), 1);
	return (0);
}

bool	print_error_msg_l_pl(char iden)
{
	if (iden == L_NBR_INFO)
		return (ft_putendl_fd("L : Invalid informations number!", 2), 1);
	else if (iden == L_COGO)
		return (ft_putendl_fd("L : Invalid coordinates format!", 2), 1);
	else if (iden == L_RATIO)
		return (ft_putendl_fd("L : Invalid ratio format!", 2), 1);
	else if (iden == L_RGB)
		return (ft_putendl_fd("L : Invalid RGB format!", 2), 1);
	else if (iden == L_DOUBLE)
		return (ft_putendl_fd("L : double element!", 2), 1);
	else if (iden == PL_NBR_INFO)
		return (ft_putendl_fd("pl : Invalid informations number!", 2), 1);
	else if (iden == PL_COGO)
		return (ft_putendl_fd("pl : Invalid coordinates format!", 2), 1);
	else if (iden == PL_ORIENT)
		return (ft_putendl_fd("pl : Invalid orientation vector format!", 2), 1);
	else if (iden == PL_RGB)
		return (ft_putendl_fd("L : Invalid RGB format!", 2), 1);
	return (0);
}

bool	print_error_msg_sp_cy(char iden)
{
	if (iden == SP_COGO)
		return (ft_putendl_fd("sp : Invalid coordinates format!", 2), 1);
	else if (iden == SP_NBR_INFO)
		return (ft_putendl_fd("sp : Invalid informations number!", 2), 1);
	else if (iden == SP_DIAMETER)
		return (ft_putendl_fd("sp : Invalid diameter format!", 2), 1);
	else if (iden == SP_RGB)
		return (ft_putendl_fd("sp : Invalid RGB format!", 2), 1);
	else if (iden == CY_NBR_INFO)
		return (ft_putendl_fd("cy : Invalid informations number!", 2), 1);
	else if (iden == CY_COGO)
		return (ft_putendl_fd("cy : Invalid coordinates format!", 2), 1);
	else if (iden == CY_ORIENT)
		return (ft_putendl_fd("cy : Invalid orientation vector format!", 2), 1);
	else if (iden == CY_DIAMETER)
		return (ft_putendl_fd("cy : Invalid diameter format!", 2), 1);
	else if (iden == CY_HEIGHT)
		return (ft_putendl_fd("cy : Invalid height format!", 2), 1);
	else if (iden == CY_RGB)
		return (ft_putendl_fd("cy : Invalid RGB format!", 2), 1);
	return (0);
}

bool	print_error_orient_vec(char iden)
{
	if (iden == 1)
		return (ft_putendl_fd("C : Invalid orientation vector!", 2), 1);
	else if (iden == 2)
		return (ft_putendl_fd("pl : Invalid orientation vector!", 2), 1);
	else if (iden == 3)
		return (ft_putendl_fd("cy : Invalid orientation vector!", 2), 1);
	return (0);
}
