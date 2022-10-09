<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

int	static word_count(char const *s, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1]) && (s[i] != c || s[i]))
			amount++;
		i++;
	}
	return (amount);
}

int	static word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void static	word_fill(char *rtn, char const *s, char c)
{
	int	i;

	i = 0;
	rtn = (char*)malloc(sizeof(char) * (word_len(s, c) + 1));
	while (s[i] != c && s[i])
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
}

void static	word_split(char **rtn, char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		else
		{
			word_fill(rtn[word], &s[i], c);
			i++;
			word++;
		}
	}
}

char **ft_split(char const *s, char c)
{
	char	**rtn;
	int		word_amount;

	word_amount = word_count(s, c);
	if (word_amount == 0)
		return (NULL);
	rtn = (char**)malloc(sizeof(char*) * (word_amount + 1)); // ASK ABOUT +1
	word_split(rtn, s, c);
	//rtn[word_amount] = 0; // ASK ABOUT THAT
	return (rtn);
}
=======
#include <stdio.h>
#include <stdlib.h>

int	static word_count(char const *s, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1]) && (s[i] != c || s[i]))
			amount++;
		i++;
	}
	return (amount);
}

int	static word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void static	word_fill(char *rtn, char const *s, char c)
{
	int	i;

	i = 0;
	rtn = (char*)malloc(sizeof(char) * (word_len(s, c) + 1));
	while (s[i] != c && s[i])
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
}

void static	word_split(char **rtn, char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		else
		{
			word_fill(rtn[word], &s[i], c);
			i++;
			word++;
		}
	}
}

char **ft_split(char const *s, char c)
{
	char	**rtn;
	int		word_amount;

	word_amount = word_count(s, c);
	if (word_amount == 0)
		return (NULL);
	rtn = (char**)malloc(sizeof(char*) * (word_amount + 1)); // ASK ABOUT +1
	word_split(rtn, s, c);
	//rtn[word_amount] = 0; // ASK ABOUT THAT
	return (rtn);
}
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
