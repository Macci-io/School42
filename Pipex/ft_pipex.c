
#include "ft_pipex.h"
#include <stdio.h>

typedef struct s_fds
{
	int fd[2];
	int	f1;
	int	f2;
	char	**env;
	char	**av;
}	t_fds;

char * find_key(char ** env, char * find){
	int i;

	i = 0; 
	while (env[i])
	{
		if(env[i] == ft_strnstr(env[i], find, ft_strlen(env[i])))
			return (&env[i][ft_strlen(find) + 1]);
		i++;
	}
	return (NULL);
}

void	err(char *msg, int exit_code)
{
	
	perror(msg);
	if (exit_code)
		exit (exit_code);
}

void	opener(t_fds * fds)
{
	char * pwd;
	char * full_path[2];

	pwd = find_key(fds->env, "PWD");
	pwd = ft_strjoin(pwd, "/");
	if (!pwd)
		err("malloc error:", 1);
	full_path[0] = ft_strjoin(pwd, fds->av[1]);
	if (!full_path[0])
		err("malloc error:", 1);
	full_path[1] = ft_strjoin(pwd, fds->av[4]);
	if (!full_path[1])
		err("malloc error:", 1);
	if (pipe(fds->fd))
		err("пайпа не смогла создать дескрипторы", 2);
	fds->f1 = open(full_path[0], O_RDONLY);
	if (fds->f1 < 0)
		err("ошибка открытия файла", 3);
	fds->f2 = open(full_path[1], O_WRONLY | O_CREAT);
	if (fds->f2 < 0)
		err("ошибка открытия файла", 1);
	free(full_path[0]);
	free(full_path[1]);
	free(pwd);
}


char	*parsway(char *spl, char **env)
{
	int	i;
	char	*str;
	char	**mss;
	char	*tmp;

	str = find_key(env, "PATH");
	mss = ft_split(str, ':'); 
	i = 0;
	while (mss[i])
	{
		str = ft_strjoin(mss[i], "/");
		tmp = str;
		str = ft_strjoin(str, spl);
		free(tmp);
		if (!access(str, 1))
			return (str);
		i++;
	}
	return (0);
}

void	sub_execute(t_fds *fds, char is_first)
{
	char ** spl;

	if (is_first && (dup2(fds->f1, 0) == -1 || dup2(fds->fd[1], 1) == -1))
		err("dup_error\n", 1);
	else if (!is_first && (dup2(fds->fd[0], 0) == -1|| dup2(fds->f2, 1) == -1))
		err("dup_error\n", 1);
	if (close(fds->f1) || close(fds->f2) || close(fds->fd[0]) || close(fds->fd[1]))
		err("close_err\n", 2);
	spl = ft_split(fds->av[3 - is_first], ' ');
	spl[0] = parsway(spl[0], fds->env);
	if (execve(spl[0], spl, fds->env) == -1)
		err("cant to execute1\n", 2);
}

void	execute(t_fds * fds)
{
	pid_t	cmd;
	
	cmd = fork();
	if (cmd < 0)
		err("error: fork cant to fork", 1);
	if (cmd == 0)
		sub_execute(fds, 1);
	cmd = fork();
	if (cmd < 0)
		err("error: fork cant to fork", 1);
	if (cmd == 0)
		sub_execute(fds, 0);
	if (close(fds->f1) || close(fds->f2) || close(fds->fd[0]) || close(fds->fd[1]))
		err("close_err\n", 5);
}


int main(int ac, char ** av, char ** env)
{
	t_fds fds;
	if (ac != 5)
		err("иди на завод", 1);
	fds.av = av;
	fds.env = env;
	opener(&fds);
	execute(&fds);
	wait(0);
	wait(0);
}