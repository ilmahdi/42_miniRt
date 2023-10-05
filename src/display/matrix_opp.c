/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_opp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:54:15 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:22:36 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	free_matrix(double **matrix, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(matrix[i]);
	free(matrix);
}

double	**alloc_matrix(double **matrix, int size)
{
	int	i;

	i = -1;
	matrix = malloc(size * sizeof(double *));
	if (!matrix)
		return (NULL);
	while (++i < size)
	{
		matrix[i] = malloc(size * sizeof(double));
		if (!matrix[i])
		{
			while (i--)
				free(matrix[i]);
			return (free(matrix), NULL);
		}
		ft_memset(matrix[i], 0, size * sizeof(double));
	}
	return (matrix);
}

double	**select_matrix(double **r, int row, int col, int size)
{
	int		i;
	int		k;
	int		l;
	int		j;
	double	**matrix;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	matrix = NULL;
	matrix = alloc_matrix(matrix, 4);
	while (i < size)
	{
		if (i != row && j != col && k < size - 1)
			matrix[k][l++] = r[i][j];
		if (++j == size && ++i)
			j = 0;
		if (l == size - 1 && ++k)
			l = 0;
	}
	return (matrix);
}

double	det_matrix(double **mtx, int size)
{
	double	**m_sel;
	double	det;
	int		i;
	int		j;

	i = 0;
	j = 0;
	det = 0;
	if (size == 1)
		return (mtx[0][0]);
	else if (size == 2)
		return (mtx[0][0] * mtx[1][1] - mtx[1][0] * mtx[0][1]);
	else
	{
		j = -1;
		while (++j < size)
		{
			m_sel = select_matrix(mtx, i, j, size);
			det += pow(-1, i + j + 2) * mtx[i][j] * det_matrix(m_sel, size - 1);
			free_matrix(m_sel, 4);
		}
	}
	return (det);
}

void	trans_matrix(double **matrix, int size)
{
	double	tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < size)
	{
		tmp = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = tmp;
		if (++j == i && i++)
			j = 0;
	}
}
