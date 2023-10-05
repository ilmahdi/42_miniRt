/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:24 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 11:40:45 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	calculate_0(char *str)
{
	int	i;
	int	nbr_0;

	i = 0;
	nbr_0 = 0;
	while (str[i] && str[i] == '0')
	{
		i++;
		nbr_0++;
	}
	return (nbr_0);
}

void	parse_ratio(char *ratio, double *var_ptr)
{
	char	**ratio_splited;
	int		nbr_0;
	double	hol;

	ratio_splited = ft_split(ratio, '.');
	hol = (double)ft_atoi(ratio_splited[0]);
	*var_ptr = hol;
	if (strlen_2d(ratio_splited) == 2)
	{
		nbr_0 = calculate_0(ratio_splited[1]);
		hol = (double)ft_atoi(ratio_splited[1]);
		while (hol >= 1)
			hol /= 10;
		hol /= pow(10, nbr_0);
		if (ratio_splited[0][0] == '-')
			*var_ptr += -hol;
		else
			*var_ptr += hol;
	}
	free_2d(ratio_splited);
}

void	parse_tuple_rgb(char *tuple, t_rgb *rgb)
{
	char	**tuple_splited;
	size_t	hol;

	tuple_splited = ft_split(tuple, ',');
	hol = ft_atoi(tuple_splited[0]);
	rgb->r = (unsigned char)hol & 0x0000ff;
	hol = ft_atoi(tuple_splited[1]);
	rgb->g = (unsigned char)hol & 0x0000ff;
	hol = ft_atoi(tuple_splited[2]);
	rgb->b = (unsigned char)hol & 0x0000ff;
	free_2d(tuple_splited);
}

void	parse_tuple_cogo(char *tuple, t_cogo *var_ptr)
{
	char	**tuple_splited;

	tuple_splited = ft_split(tuple, ',');
	parse_ratio(tuple_splited[0], &(var_ptr->x));
	parse_ratio(tuple_splited[1], &(var_ptr->y));
	parse_ratio(tuple_splited[2], &(var_ptr->z));
	free_2d(tuple_splited);
}
