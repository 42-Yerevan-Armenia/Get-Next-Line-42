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

char	*mywhile(int fd, char *sline)
{
	char	buffer[BUFFER_SIZE + 1];
	long	rsize;

	rsize = 0;
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
	static char	*sline[OPEN_MAX];//calling to open MAX (1024) files
	char		*until_n;
	char		*tline;
	long		slinelen;

	sline[fd] = mywhile(fd, rsize, sline[fd]);//just our [fd]
	if (!sline[fd])
		return (NULL);
	slinelen = ft_strlen(sline[fd]) - ft_strlen(ft_strchr(sline[fd], '\n')) + 1;
	until_n = ft_substr(sline[fd], 0, slinelen);
	tline = sline[fd];
	sline[fd] = ft_substr(sline[fd], slinelen, ft_strlen(sline[fd]));
	free(tline);
	return (until_n);
}

int	main(void)
{
	int	i;
	int	fd;
	int fd2;

	i = 10;
	fd = open("gnl.txt", O_RDONLY);
	fd2 = open("gnl2.txt", O_RDONLY);
//printf("%s\n", get_next_line(fd));	
//printf("%s\n", get_next_line(fd2));
//printf("%s\n", get_next_line(fd));
//printf("%s\n", get_next_line(fd2));
	 while (i != 0)
	 {
	 	printf("%s\n", get_next_line(fd));
	 	printf("%s\n", get_next_line(fd2));
	 	i--;
	 }
}
