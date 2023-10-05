/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_opp_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:56:12 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:22:49 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	dot_2d(t_cogo	v_one, t_cogo v_two)
{
	double	r;

	r = (v_one.x * v_two.x) + (v_one.y * v_two.y);
	return (r);
}

void	add_sub_vectors_2d(t_cogo *v_res, t_cogo v_one, t_cogo v_two, int s)
{
	v_res->x = v_one.x + (s * v_two.x);
	v_res->y = v_one.y + (s * v_two.y);
}

double	mag_vector_2d(t_cogo vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2)));
}

void	resize_vec_2d(t_cogo *vec, t_cogo v, double len)
{
	double	hol_mag;

	hol_mag = mag_vector_2d(v);
	vec->x = (len / hol_mag) * v.x;
	vec->y = (len / hol_mag) * v.y;
}
