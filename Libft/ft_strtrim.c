/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:07:30 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:07:30 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	set_in(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i++])
		if (set[i] == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	first;
	size_t	last;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	first = 0;
	last = ft_strlen((char *)s1);
	while (set_in(&s1[first], (char)set) == 0)
		first++;
	while (set_in(&s1[last - 1], (char)set) == 0)
		last--;
	if ((size_t)ft_strlen((char *)s1) <= first + last)
		return (NULL);
	rtn = ft_substr(s1, first, last - first);
	return (rtn);
}
