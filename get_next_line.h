/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:31:10 by hienguye          #+#    #+#             */
/*   Updated: 2024/01/20 14:31:12 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>


char	*get_next_line(int fd);

char	*ft_strdup(char *str);
char	*ft_strchr(const char *str, int character);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num_elements, size_t element_size);

#endif