/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:02:59 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:02:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	word_count(char const *s, char c)
{
	int	rtn;

	rtn = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			rtn++;
		s++;
	}
	return (rtn);
}

int	static	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

int	static	word_fill(char const *s, char c, char **d, size_t w_amount)
{
	size_t	i;
	size_t	word;
	size_t	s_size;
	size_t	s_sub;

	i = 0;
	word = 0;
	s_size = ft_strlen(s);
	while (word < w_amount)
	{
		while (s[i] == c && i < s_size)
			i++;
		s_sub = word_len(&s[i], c);
		d[word] = ft_substr(s, i, s_sub);
		if (d[word] == NULL)
			return (-1);
		word++;
		while (s[i] != c && i < s_size)
			i++;
	}
	return (0);
}

void static	*ft_free2m(char	**data)
{
	int	i;

	i = 0;
	if (!data)
		return (NULL);
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	if (!data)
		return (NULL);
	return (data);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		w_amount;

	if (!s)
		return (NULL);
	w_amount = word_count(s, c);
	rtn = (char **)ft_calloc(w_amount + 1, sizeof(char *));
	if (!rtn)
		return (NULL);
	if (word_fill((char *)s, c, rtn, w_amount) == -1)
		return (ft_free2m(rtn));
	return (rtn);
}
