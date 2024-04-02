/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:30:38 by hienguye          #+#    #+#             */
/*   Updated: 2024/01/20 14:30:41 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	s1 = temp;
	return (s1);
}

char	*ft_remove_line(char *buffer)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i++;
	res = ft_strdup(&buffer[i]);
	free(buffer);
	return (res);
}

char	*ft_read_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i= 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!res)
		res = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res || !buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		res = ft_realloc(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_remove_line(buffer);
	return (line);
}
/*
int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
*/
