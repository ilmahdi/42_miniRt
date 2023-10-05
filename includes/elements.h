/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:30:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 12:20:33 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "./minirt.h"

typedef struct s_cogo
{
	double	x;
	double	y;
	double	z;
}	t_cogo;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_elem_nbr
{
	size_t	a_nbr;
	size_t	c_nbr;
	size_t	l_nbr;
	size_t	sp_nbr;
	size_t	pl_nbr;
	size_t	cy_nbr;
	size_t	co_nbr;
}	t_elem_nbr;

typedef struct s_amb_light
{
	double	ratio;
	t_rgb	rgb;
	bool	single;
}	t_amb_light;

typedef struct s_camera
{
	t_cogo	pos;
	t_cogo	orient;
	double	fov;
	t_rgb	rgb;
}	t_camera;

typedef struct s_light
{
	t_cogo	pos;
	double	bright;
	t_rgb	rgb;
}	t_light;

typedef struct s_sphere
{
	t_cogo	pos;
	double	diameter;
	t_rgb	rgb;
}	t_sphere;

typedef struct s_plane
{
	t_cogo	pos;
	t_cogo	orient;
	t_cogo	limits;
	t_rgb	rgb;
}	t_plane;

typedef struct s_cylinder
{
	double	**m_pos;
	t_cogo	pos;
	t_cogo	orient;
	t_cogo	o_c;
	double	z_o;
	double	diameter;
	double	height;
	t_rgb	rgb;
}	t_cylinder;

typedef struct s_cone
{
	t_cogo	orient;
	t_cogo	m_p;
	t_cogo	m_o;
	t_cogo	pos;
	t_cogo	o_c;
	double	base;
	double	hgt;
	t_rgb	rgb;
	double	**m_pos;
}	t_cone;

typedef struct s_elements
{
	t_amb_light	*a;
	t_camera	*c;
	t_light		*l;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_cone		*co;
	t_elem_nbr	elem_nbr;
	t_cogo		origin;
	double		**m_pos;
}	t_elements;

#endif
