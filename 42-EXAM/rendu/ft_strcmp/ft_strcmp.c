
int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/* #include <string.h>
#include <stdio.h>
int main()
{
	printf("%d\n", strcmp("",""));
	printf("%d\n", strcmp("","ab"));
	printf("%d\n", strcmp("ab",""));
	printf("%d\n", strcmp("ab","ab"));
	printf("%d\n", strcmp("abe","abc"));
	printf("%d\n", strcmp("g","c"));
	printf("%d\n", strcmp("c","g"));

	printf("\n%d\n", ft_strcmp("",""));
	printf("%d\n", ft_strcmp("","ab"));
	printf("%d\n", ft_strcmp("ab",""));
	printf("%d\n", ft_strcmp("ab","ab"));
	printf("%d\n", ft_strcmp("abe","abc"));
	printf("%d\n", ft_strcmp("g","c"));
	printf("%d\n", ft_strcmp("c","g"));
} */
