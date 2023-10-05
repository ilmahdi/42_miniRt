/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:18:35 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/15 22:18:33 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_win(t_elements *elem)
{
	free_elements(elem);
	exit(0);
	return (0);
}

int	close_win_esc(int keycode, t_elements *elem)
{
	if (keycode == ESC_KEY)
	{
		free_elements(elem);
		exit(0);
	}
	return (0);
}

void	free_elements(t_elements *elem)
{
	int	i;

	i = -1;
	if (elem->m_pos)
		free_matrix(elem->m_pos, 4);
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (elem->cy[i].m_pos)
			free_matrix(elem->cy[i].m_pos, 4);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (elem->co[i].m_pos)
			free_matrix(elem->co[i].m_pos, 4);
	free(elem->a);
	free(elem->c);
	free(elem->l);
	free(elem->sp);
	free(elem->pl);
	free(elem->cy);
	free(elem->co);
}

int	main(int ac, char **av)
{
	t_elements	elem;
	t_mlx_ptr	gfx;

	elem = (t_elements){};
	gfx = (t_mlx_ptr){};
	if (ac != 2)
		map_invalid(INVALID_N_ARGS);
	read_map(&elem, av[1]);
	gfx.mlx = mlx_init();
	gfx.win = mlx_new_window(gfx.mlx, 1000, 1000, NAME_W);
	gfx.img = mlx_new_image(gfx.mlx, 1000, 1000);
	gfx.buf = mlx_get_data_addr(gfx.img, &gfx.p_bits, &gfx.l_bytes, &gfx.endn);
	call_display_function(&elem, &gfx);
	mlx_put_image_to_window(gfx.mlx, gfx.win, gfx.img, 0, 0);
	mlx_hook(gfx.win, 2, 0L, close_win_esc, &elem);
	mlx_hook(gfx.win, 17, 0L, close_win, &elem);
	mlx_loop(gfx.mlx);
	free_elements(&elem);
	return (0);
}
