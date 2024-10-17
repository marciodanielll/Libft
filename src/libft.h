/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:34:18 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/17 18:48:28 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);
//char	*ft_strnstr(const char *big, const char *little, size_t len);
//size_t	ft_strlcat(char *dst, const char *src, size_t size);
//int		ft_toupper(int c);
//int		ft_tolower(int c);

// int		ft_atoi(const char *str);

#endif /*LIBFT_H*/

/*
ft_atoi -
ft_bzero -
ft_isalnum
ft_isalpha
ft_isascii
ft_isdigit
ft_isprint
ft_memchr -
ft_memcmp -
ft_memcpy -
ft_memmove -
ft_memset -
ft_strchr
ft_strlcat
ft_strlcpy
ft_strlen
ft_strncmp
ft_strnstr
ft_strrchr
ft_tolower
ft_toupper
*/