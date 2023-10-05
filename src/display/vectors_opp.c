/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:05:47 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:19:50 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	dot(t_cogo	v_one, t_cogo v_two)
{
	return ((v_one.x * v_two.x) + (v_one.y * v_two.y) + (v_one.z * v_two.z));
}

void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe)
{
	v_res->x = v_one.x + (signe * v_two.x);
	v_res->y = v_one.y + (signe * v_two.y);
	v_res->z = v_one.z + (signe * v_two.z);
}

double	mag_vector(t_cogo vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

void	scaler_multiplication(t_cogo *vec, t_cogo v, double scaler)
{
	vec->x = scaler * v.x;
	vec->y = scaler * v.y;
	vec->z = scaler * v.z;
}

void	resize_vec(t_cogo *vec, t_cogo v, double len)
{
	double	hol_mag;

	hol_mag = mag_vector(v);
	vec->x = (len / hol_mag) * v.x;
	vec->y = (len / hol_mag) * v.y;
	vec->z = (len / hol_mag) * v.z;
}
