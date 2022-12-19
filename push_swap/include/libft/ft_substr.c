/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:09:59 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:09:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
