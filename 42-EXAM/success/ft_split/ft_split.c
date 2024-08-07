#include <stdlib.h>

void ft_strncpy(char *src, char *dest, int n)
{
	int i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char    **ft_split(char *str)
{
	int i = 0;
	int i_delimeter = 0;
	int i_array = 0;
	int word_len = 0;
	int word_count = 0;
	char **array_of_words = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
	}

	array_of_words = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
			i++;
		i_delimeter = i;
		while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
		if (i > i_delimeter)
		{
			word_len = i - i_delimeter;
			array_of_words[i_array] = malloc(sizeof(char) * (word_len + 1));
			ft_strncpy(&str[i_delimeter], array_of_words[i_array], word_len);
			i_array++;
		}
	}
	array_of_words[i_array] = NULL;
	return (array_of_words);
}
/*
#include <stdio.h>
int main()
{
	char **result = ft_split("");

	while (*result)
	{
		printf("%s\n", *result);
		result++;
	}
} */
