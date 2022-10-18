/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:04:05 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:04:05 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
