/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:07:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 08:29:52 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	alloc(void **ptr, size_t len)
{
	if (!len)
		return (0);
	*ptr = malloc(len);
	if (!*ptr)
		return (1);
	ft_memset(*ptr, 0, len);
	return (0);
}

size_t	strlen_2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	free_2d(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
		free(strs[i]);
	free(strs);
}

char	*get_next_line(int fd)
{
	char	hhol[10000];
	char	hol[2];
	char	*line;
	int		rt;
	int		i;

	i = 0;
	while (1)
	{
		rt = read(fd, hol, 1);
		if (rt <= 0)
			break ;
		hol[1] = '\0';
		hhol[i] = hol[0];
		i++;
		hhol[i] = '\0';
		if (hol[0] == '\n' || hol[0] == '\0')
			break ;
	}
	if (i == 0 || rt == -1)
		return (NULL);
	line = (char *)ft_calloc((size_t)(i + 1), sizeof(char));
	if (!line)
		return (NULL);
	return (ft_strlcpy(line, hhol, (ft_strlen(hhol)) + 1), line);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	if (s1 != NULL)
		j = ft_strlen(s1);
	s = (char *)malloc((size_t)(j + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (s);
}
