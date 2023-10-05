/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:14:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/13 15:27:01 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	allocate_elements(t_elements *elem)
{
	if (alloc((void **)&elem->a, sizeof(t_amb_light) * (elem->elem_nbr.a_nbr)))
		return (0);
	if (alloc((void **)&elem->c, sizeof(t_camera) * (elem->elem_nbr.c_nbr)))
		return (free(elem->a), 0);
	if (alloc((void **)&elem->l, sizeof(t_light) * (elem->elem_nbr.l_nbr)))
		return (free(elem->a), free(elem->c), 0);
	if (alloc((void **)&elem->sp, sizeof(t_sphere) * (elem->elem_nbr.sp_nbr)))
		return (free(elem->a), free(elem->c), free(elem->l), 0);
	if (alloc((void **)&elem->pl, sizeof(t_plane) * (elem->elem_nbr.pl_nbr)))
		return (free(elem->a), free(elem->c), free(elem->l), free(elem->sp), 0);
	if (alloc((void **)&elem->cy, sizeof(t_cylinder) * (elem->elem_nbr.cy_nbr)))
		return (free(elem->a), free(elem->c), free(elem->l), free(elem->sp), \
				free(elem->pl), 0);
	if (alloc((void **)&elem->co, sizeof(t_cone) * (elem->elem_nbr.co_nbr)))
		return (free(elem->a), free(elem->c), free(elem->l), free(elem->sp), \
				free(elem->pl), free(elem->cy), 0);
	return (1);
}

void	check_map(t_elements *elem, char **map)
{
	int		i;
	char	iden;

	i = -1;
	while (map[++i])
	{
		iden = check_element(elem, map[i], 'x');
		if (iden != 'x')
		{
			free_2d(map);
			map_invalid(iden);
		}
	}
	if (check_double_elements_a_c_l(elem->elem_nbr, &iden)
		|| !allocate_elements(elem))
		return (free_2d(map), map_invalid(iden));
	i = -1;
	while (map[++i])
		check_element(elem, map[i], 'X');
	iden = check_valid_orient_vec(elem);
	if (!elem->elem_nbr.c_nbr)
		iden = 'U';
	if (iden)
		return (free_2d(map), free_elements(elem), map_invalid(iden));
	free_2d(map);
}

void	read_map(t_elements *elem, char *f_map)
{
	char	**map;
	char	*hget;
	char	*hol;
	int		fd;

	if (ft_strncmp(".rt", &f_map[ft_strlen(f_map) - 3], 3))
		map_invalid(INVALID_EXTENSION);
	fd = open(f_map, O_RDONLY);
	hol = NULL;
	while (1)
	{
		hget = get_next_line(fd);
		if (!hget)
			break ;
		hol = ft_strjoin2(hol, hget);
	}
	close(fd);
	if (!hol)
		map_invalid(EMPTY_MAP);
	map = ft_split(hol, '\n');
	free(hol);
	check_map(elem, map);
}
