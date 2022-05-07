/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:22:46 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/03 16:23:19 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>//main
# include <fcntl.h>//main

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

char	*get_next_line(int fd);
char	*mywhile(int fd, long rsize, char *sline);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(char *s);

#endif