/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 19:24:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/01 22:38:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	ret;

	ret = 0;
	while (c[ret])
		ret++;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*rtn;

	i = 0;
	j = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s1 || !s2 || !rtn)
		return (NULL);
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	while (s2[j])
		rtn[i++] = s2[j++];
	rtn[i] = '\0';
	return (rtn);
}

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if (n == i)
			return (d);
	}
	return (d);
}

char	*ft_strdup(char const *s1)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		rtn[i] = s[i + start];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
