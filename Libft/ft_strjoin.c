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
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ft_strlen((char *)s1) + ft_strlen((char *)s2)))
		return (NULL);
	ret = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	while (s1[i++])
		ret[i] = s1[i];
	while (s2[j++])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}
