/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:00:34 by vmoroz            #+#    #+#             */
/*   Updated: 2023/10/12 12:36:09 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 10000
// #endif

char	*get_next_line(int fd);
char	*ft_read_to_next_str(int fd, char *next_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *next_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *next_str);
char	*ft_new_next_str(char *next_str);

#endif