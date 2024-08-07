#include <stdio.h>
#include <stdlib.h>

void ft_strncpy(char *src , char *dest, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
}

char    **ft_split(char *str)
{
	int	word_count = 0;
	int i = 0;
	int i_checkpoint = 0;
	int word_len = 0;
	int i_array = 0;
	// char *str = "Hello worsadld\taskdasjhd\najshd";
	char **array_of_strings = 0;

	while (str[i])
	{
		while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
			i++;
		if (str[i])
			word_count++;
		while (str[i] != '\0' && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
	}
	array_of_strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array_of_strings == NULL)
		return NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
			i++;
		i_checkpoint = i;
		while (str[i] != '\0' && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
		if (i > i_checkpoint)
		{
			word_len = i - i_checkpoint;
			array_of_strings[i_array] = (char *)malloc(sizeof(char) * (word_len + 1));
			ft_strncpy(&str[i_checkpoint], array_of_strings[i_array], word_len);
			i_array++;
		}
	}
	array_of_strings[i_array] = NULL;
	return array_of_strings;
}

// Test function
int main()
{
    char test_str[] = "Hello world\tthis is a test\nwith multiple delimiters";
    char **result = ft_split(test_str);

    if (result == NULL)
    {
        perror("Failed to split string");
        return EXIT_FAILURE;
    }

    // Print the result
    char **temp = result;
    while (*temp)
    {
        printf("Word: '%s'\n", *temp);
        temp++;
    }

    return EXIT_SUCCESS;
}
