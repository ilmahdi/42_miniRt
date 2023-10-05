/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:03 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 08:29:32 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_limit(char *ratio, double min, double max)
{
	double	hol;

	parse_ratio(ratio, &hol);
	if (hol < min || hol > max)
		return (1);
	return (0);
}

bool	check_dot(char *ratio, bool signe, bool dot)
{
	char	n_dot;
	int		i;

	n_dot = 0;
	i = 0;
	if (signe)
		if (ratio[i] == '+' || ratio[i] == '-')
			i++;
	while (ratio[i])
	{
		if (!dot && ratio[i] == '.')
			return (1);
		if (ratio[i] == '.')
			n_dot++;
		if ((!ft_isdigit(ratio[i]) && ratio[i] != '.') || n_dot > 1)
			return (1);
		i++;
	}
	if (ratio[i - 1] == '.' || ratio[0] == '.')
		return (1);
	return (0);
}

bool	check_tuple(char *tuple, int type, bool signe, bool dot)
{
	char	**tuple_splited;
	int		i;

	tuple_splited = ft_split(tuple, ',');
	if (strlen_2d(tuple_splited) != 3)
		return (free_2d(tuple_splited), 1);
	i = 0;
	while (tuple_splited[i])
	{
		if (check_dot(tuple_splited[i], signe, dot))
			return (free_2d(tuple_splited), 1);
		if (type == 0)
			if (ft_atoi(tuple_splited[i]) > 255)
				return (free_2d(tuple_splited), 1);
		if (type == 1)
			if (check_limit(tuple_splited[i], -1, 1))
				return (free_2d(tuple_splited), 1);
		i++;
	}
	return (free_2d(tuple_splited), 0);
}

bool	check_three_null(t_cogo v)
{
	if (!v.x && !v.y && !v.z)
		return (1);
	return (0);
}

int	check_valid_orient_vec(t_elements *elem)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.c_nbr)
		if (check_three_null(elem->c->orient))
			return (1);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (check_three_null(elem->pl->orient))
			return (2);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (check_three_null(elem->cy->orient))
			return (3);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (check_three_null(elem->co->orient))
			return (4);
	return (0);
}
