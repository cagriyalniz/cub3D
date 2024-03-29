/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:46:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/28 12:07:46 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


char	*f_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	res[0] = '\0';
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcpy(res + len1, s2, len2 + 1);
	free(s1);
	return (res);
}

char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (0);
	while (*str != '\0' && (char)ch != *str)
		str++;
	if ((char)ch == *str)
		return ((char *)str);
	return (0);
}

char	*ft_get_one_line(char *left_str) // alt satira kayma durumundan kurtulmak icin
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


char	*ft_new_left_str(char *left_str) // static olarak tanimlanan degiskende bir onceki satir haricindeki tutma
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)ft_calloc(sizeof(char),(ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*ft_search_n_str(int fd, char *left_str) // \n gorene kadar elemanlari tutma(alt satira kayma durumunda ft_get_one_line fonksiyonu kullaniliyor)
{
	char	*buff;
	int		rd_bytes;

	buff = ft_calloc((BUFFER_SIZE + 1),sizeof(char));
	buff[0] = '\0';
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = f_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_search_n_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_one_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
