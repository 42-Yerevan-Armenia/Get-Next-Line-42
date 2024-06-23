/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <arakhurs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:21:57 by arakhurs          #+#    #+#             */
/*   Updated: 2024/06/23 20:59:03 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*sline[OPEN_MAX];
	char		*until_n;
	char		*tline;
	long		slinelen;

	//if (fd < 3 || buffer < 65536 || BUFFER_SIZE <= 0)
	//	return (0);
	sline[fd] = mywhile(fd, sline[fd]);
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
	int 	fd2;
	char	*ch1;
	char	*ch2;

	i = 10;
	fd = open("gnl.txt", O_RDONLY);
	fd2 = open("gnl2.txt", O_RDONLY);
//printf("%s\n", get_next_line(fd));	
//printf("%s\n", get_next_line(fd2));
//printf("%s\n", get_next_line(fd));
//printf("%s\n", get_next_line(fd2));
	 while (i--)
	 {
		 ch1 = get_next_line(fd1);
		 ch2 = get_next_line(fd2);
		 printf("%s\n", ch1);
		 printf("%s\n", ch2);
		 free(ch);
	 }
	close(fd);
}