/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:21:57 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:05 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*mywhile(int fd, long rsize, char *sline)
{
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{	
		rsize = read(fd, buffer, BUFFER_SIZE);
		buffer[rsize] = '\0';
		if (rsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buffer);
		else
			sline = ft_strjoin(sline, buffer);
		if (ft_strchr(buffer, '\n') || rsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	static char	*sline[OPEN_MAX];
	char		*until_n;
	char		*tline;
	long		rsize;
	long		slinelen;

	rsize = 1;
	if (rsize == 0)
		return (NULL);
	//if (fd < 3 || buffer < 65536 || BUFFER_SIZE <= 0)
	//	return (0);
	sline[fd] = mywhile(fd, rsize, sline[fd]);
	if (!sline[fd])
		return (NULL);
	slinelen = ft_strlen(sline[fd]) - ft_strlen(ft_strchr(sline[fd], '\n')) + 1;
	until_n = ft_substr(sline[fd], 0, slinelen);
	tline = sline[fd];
	sline[fd] = ft_substr(sline[fd], slinelen, ft_strlen(sline[fd]));
	free(tline);
	return (until_n);
}
