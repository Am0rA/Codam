/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:03:45 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:03:45 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
}
