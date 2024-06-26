/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:47:38 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/03 13:25:04 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (0);
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*ft_get_read(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!stash || (!ft_strchr(stash, '\n') && read_bytes != 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(stash), NULL);
		buffer[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	char	*tmp;
	size_t	size;

	if (!*stash)
		return (NULL);
	tmp = stash;
	while (*tmp && *tmp != '\n')
		tmp++;
	size = tmp - stash;
	line = (char *)malloc(sizeof(char) * ((size) + 2));
	if (!line)
		return (NULL);
	tmp = stash;
	ft_memmove(line, tmp, size + 1);
	line[size + 1] = '\0';
	return (line);
}

char	*ft_backup_line(char *stash)
{
	char	*backup;
	char	*tmp;
	size_t	size;

	tmp = stash;
	while (*tmp != '\n' && *tmp != '\0')
		tmp++;
	if (!*tmp)
	{
		free(stash);
		return (NULL);
	}
	size = ft_strlen(tmp);
	backup = (char *)malloc(sizeof(char) * (size + 1));
	if (!backup)
		return (NULL);
	tmp++;
	ft_memmove(backup, tmp, size);
	backup[size] = '\0';
	free(stash);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[FD_MAX];

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_get_read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_backup_line(stash[fd]);
	return (line);
}
