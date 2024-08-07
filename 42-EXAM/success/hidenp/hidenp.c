#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i_hidden_s1 = 0;
	int i_s2 = 0;
	// printf("fine");
	if (argc == 3)
	{
		if (argv[1][i_hidden_s1] == '\0')
			{
				write (1,"1\n",2);
				return (0);
			}
		while (argv[2][i_s2] != '\0' && argv[1][i_hidden_s1] != '\0')
		{
			if (argv[2][i_s2] == argv[1][i_hidden_s1])
				i_hidden_s1++;
			i_s2++;
		}
		if (i_hidden_s1 == ft_strlen(&argv[1][0]))
			write (1,"1",1);
		else
			write (1,"0",1);
	}
	write (1,"\n",1);
}
