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

int static unsigned	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		rtn_size;
	char	*rtn_first;
	char	*rtn_last;
	char	*rtn;

	i = 0;
	while (in_set(s1[i], set))
		i++;
	rtn_first = (char *)&s1[i];
	i = ft_strlen((char *)s1) - 1;
	while (in_set(s1[i], set) && i >= 0)
		i--;
	rtn_last = (char *)&s1[i];
	rtn_size = rtn_first - rtn_last + 2;
	rtn = malloc(sizeof(char) * (rtn_size));
	ft_strlcpy(rtn, rtn_first, rtn_size);
	return (rtn);
}
