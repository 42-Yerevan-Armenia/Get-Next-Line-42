/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <arakhurs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:21:57 by arakhurs          #+#    #+#             */
/*   Updated: 2024/06/23 21:02:06 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

char	*mywhile(int fd, char *sline)
{
	char	buffer[BUFFER_SIZE + 1];
	long	rsize;

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
	static char	*sline;
	char		*until_n;
	char		*tline;
	long		slinelen;

	sline = mywhile(fd, sline);
	if (!sline)
		return (NULL);
	slinelen = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	until_n = ft_substr(sline, 0, slinelen);
	tline = sline;
	sline = ft_substr(sline, slinelen, ft_strlen(sline));
	free(tline);
	return (until_n);
}

int	main(void)
{
	int	i;
	int	fd;
	char	*ch;

	i = 5;
	fd = open("gnl2.txt", O_RDONLY);
//printf("%s\n", get_next_line(fd));
//printf("%s\n", get_next_line(fd));
	while (i--)
	 {
		ch = get_next_line(fd);
	 	printf("%s\n", ch);
		free(ch);
	 }
	close(fd);
	//while(1) check memory leak by typing in terminal "ps", after "leaks 9357(random number)"
	//	return (0);
}
