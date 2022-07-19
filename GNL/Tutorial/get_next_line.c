/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:21:57 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:05 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;//line where we working
	char		*until_n;
	char		*tline;//temporary line
	long		slinelen;//long

	sline = mywhile(fd, rsize, sline);
	if (!sline)
		return (NULL);
	slinelen = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;//[-------1--------\n---2--] finding sizeof 1
	until_n = ft_substr(sline, 0, slinelen);//[-------1--------\n---2--] cuting and saving 1 from static
	tline = sline;//giving temporary adrees for free
	sline = ft_substr(sline, slinelen, ft_strlen(sline));//taking after \n to next static
	free(tline);
	return (until_n);
}

char	*mywhile(int fd, char *sline)
{
	char	buffer[BUFFER_SIZE + 1];
	long	rsize;//read size

	while (1)//cycle is true
	{	
		rsize = read(fd, buffer, BUFFER_SIZE);//taking size of readed buffer
		buffer[rsize] = '\0';//end of buffer
		if (rsize == -1)//if Error fd(-1) = 0
			return (0);
		if (!sline)
			sline = ft_strdup(buffer);//saving buffer in static
		else
			sline = ft_strjoin(sline, buffer);//joining next buffer to our static
		if (ft_strchr(buffer, '\n') || rsize == 0)//stop when founding /n or if nothing to read
			break ;
	}
	return (sline);
}

int	main(void)
{
	int	i;
	int	fd;
	char	*ch;

	i = 20;
	fd = open("gnl.txt", O_RDONLY);
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
