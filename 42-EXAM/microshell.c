#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int ft_error(char *s, char *args)
{
	write(2, s, ft_strlen(s));
	if (args)
		write(2, args, ft_strlen(args));
	write(2, "\n", 1);
	return (1);
}

int ft_execute(int i, int tmp_fd, char **av, char **envp)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, envp);
	return (ft_error("error: cannot execute ", av[0]));
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	int i = 0, pid = -1, tmp_fd, fd[2];

	tmp_fd = dup(STDIN_FILENO);
	while(av[i] && av[i + 1])
	{
		av = av + i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";")))
		{
			pid = fork();
			if (pid == 0)
			{
				if (ft_execute(i, tmp_fd, av, envp))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
				;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp(av[i], "|"))
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(i, tmp_fd, av, envp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = dup(fd[0]);
			}
		}
	}
	close(tmp_fd);
}
