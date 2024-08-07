#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i_s = 0;
	int i_reject = 0;

	if (reject == '\0')
	{
		while (s[i_s])
			i_s++;
		return (i_s);
	}
	else if (reject == '\0' && s == '\0' || s == '\0')
		return (0);
	i_s = 0;
	while (s[i_s])
	{
		i_reject = 0;
		while (reject[i_reject])
		{
			if (s[i_s] == reject[i_reject])
				return (i_s);
			i_reject++;
		}
		i_s++;
	}
	return (i_s);
}

/*

int main()
{
	printf("%lu", strcspn("", "123"));
	printf("%lu", ft_strcspn("", "123"));
} */
