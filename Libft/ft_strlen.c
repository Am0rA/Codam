/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:05:26 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:05:26 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *c)
{
	int	ret;

	if (!c)
		return (0);
	ret = 0;
	while (c[ret])
		ret++;
	return (ret);
}
