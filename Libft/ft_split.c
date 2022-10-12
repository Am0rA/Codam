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

int    static    word_count(char const *s, char c)
{
    int    rtn;

    rtn = 0;
    while (*s)
    {
        if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
            rtn++;
        s++;
    }
    return (rtn);
}

char static    *word_fill(char const *s, char c, char *d)
{
    int i;

    i = 0;
    if (!s || !c)
        return (0);
    while (*s == c || *s == '\0')
        s++;
    while (*s != c && *s != '\0')
    {
        i++;
        s++;
    }
    d = ft_substr((s - i), 0, i);
    return ((char *)s);
}

char    **ft_split(char const *s, char c)
{
    char  **rtn;
    char  *bs;
    int   i;
    int   w_amount;

    i = 0;
    bs = (char *)s;
    w_amount = (word_count(bs, c));
    rtn = (char **)malloc(sizeof(char*) * (w_amount));
    while (i < w_amount)
    {
        bs = word_fill(bs, c, rtn[i]);
        i++;
    }
    return (rtn);
}