/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:54:15 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 07:42:05 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	comlete_rotation_y(double x, double z, double *ang)
{
	if (x < 0 && z >= 0)
		(*ang) = (2 * M_PI) - (*ang);
	else if (x > 0 && z < 0)
		(*ang) = M_PI - (*ang);
	else if (x <= 0 && z < 0)
		(*ang) = M_PI + (*ang);
}

void	comlete_rotation_x(double y, double z, double *ang)
{
	if (y > 0 && z >= 0)
		(*ang) = (2 * M_PI) - (*ang);
	else if (y > 0 && z < 0)
		(*ang) = M_PI + (*ang);
	else if (y < 0 && z < 0)
		(*ang) = M_PI - (*ang);
}

void	inverse_matrix(double **adjoint, double **matrix, int size)
{
	double	**m_sel;
	double	det_2;
	double	det;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = 0;
	j = 0;
	det = det_matrix(matrix, 4);
	while (i < size)
	{
		m_sel = select_matrix(matrix, i, j, size);
		det_2 = det_matrix(m_sel, size - 1);
		adjoint[i][j] = (pow(-1, i + j + 2) * det_2) / det;
		if (++j == size && ++i)
			j = 0;
		free_matrix(m_sel, 4);
	}
	trans_matrix(adjoint, size);
}

void	fill_sub_matrix(t_cogo v, double **t_y, double **t_x)
{
	double	teta;
	double	beta;

	if (v.x || v.z)
		teta = acos(fabs(v.z) / sqrt(pow(v.z, 2)
					+ pow(v.x, 2)));
	comlete_rotation_y(v.x, v.z, &teta);
	t_y[0][0] = cos(teta);
	t_y[0][2] = sin(teta);
	t_y[1][1] = 1;
	t_y[2][0] = -sin(teta);
	t_y[2][2] = cos(teta);
	t_y[3][3] = 1;
	v.z = fabs(v.z);
	beta = acos(sqrt(pow(mag_vector(v), 2)
				- pow(v.y, 2)) / mag_vector(v));
	comlete_rotation_x(v.y, v.z, &beta);
	t_x[0][0] = 1;
	t_x[1][1] = cos(beta);
	t_x[1][2] = -sin(beta);
	t_x[2][1] = sin(beta);
	t_x[2][2] = cos(beta);
	t_x[3][3] = 1;
}

void	fill_main_matrix(double **t_pos, double **t_y, double **t_x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		t_pos[i][j] = (t_y[i][0] * t_x[0][j]) + (t_y[i][1] * t_x[1][j])
			+ (t_y[i][2] * t_x[2][j]) + (t_y[i][3] * t_x[3][j]);
		if (++j == 4 && ++i)
			j = 0;
	}
}
