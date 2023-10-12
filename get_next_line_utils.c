/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:13:41 by vmoroz            #+#    #+#             */
/*   Updated: 2023/10/05 14:33:48 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *next_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!next_str)
	{
		next_str = (char *)malloc(1 * sizeof(char));
		next_str[0] = '\0';
	}
	if (!next_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(next_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (next_str)
		while (next_str[++i] != '\0')
			str[i] = next_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(next_str) + ft_strlen(buff)] = '\0';
	free(next_str);
	return (str);
}

char	*ft_get_line(char *next_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!next_str[i])
		return (NULL);
	while (next_str[i] && next_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (next_str[i] && next_str[i] != '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	if (next_str[i] == '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_next_str(char *next_str)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free(next_str);
	return (str);
}
