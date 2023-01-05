/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 02:39:04 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/30 02:39:04 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Depending on status it will open the document as input or output.
int	ft_openfile(char *path, char *status)
{
	int	fd;

	if (ft_strcmp(status, "out") == 0)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else
		fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("Open file fail", EXIT_FAILURE);
	return (fd);
}

char	*find_full_path(char *cmd, char **dirs)
{
	char	*full_path;
	int		i;

	i = -1;
	while (dirs[++i])
	{
		full_path = ft_strjoin(dirs[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, F_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
	}
	return (full_path);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	i = -1;
	path = NULL;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i];
			break ;
		}
	if (!path)
		return (NULL);
	paths = ft_split(path + 5, ':');
	full_path = find_full_path(cmd, paths);
	free_vector(paths);
	return (full_path);
}

/*Prints the error than exits the program by cleaning 
up and releasing any resources that program was using.*/
void	error_exit(const char *error, int exit_code)
{
	write(STDERR_FILENO, "Pipex error: ", 13);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(exit_code);
}

void	exec_cmd(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**args;

	i = 0;
	args = ft_split(cmd, ' ');
	path = find_path(cmd, envp);
	if (!path)
		error_exit("Path not found", EXIT_FAILURE);
	execve(path, args, envp);
	error_exit("Command not found", EXIT_FAILURE);
}

void	exec_child(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_exit("pipe failed", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		error_exit("fork failed", EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[READ]);
		if (dup2(fd[WRITE], STDOUT_FILENO) == -1)
			error_exit("dup2 WRITE failed", EXIT_FAILURE);
		exec_cmd(cmd, envp);
	}
	else if (pid > 0)
	{
		close(fd[WRITE]);
		if (dup2(fd[READ], STDIN_FILENO) == -1)
			error_exit("dup2 READ failed", EXIT_FAILURE);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	in;
	int	out;

	i = 2;
	if (ac < 5)
		error_exit("Invalid use! ./pipex <in> <cmdN> <out>", EXIT_FAILURE);
	in = ft_openfile(av[1], "in");
	out = ft_openfile(av[ac - 1], "out");
	if (dup2(in, STDIN_FILENO) < 0);
		error_exit("dup2 for in failed", EXIT_FAILURE);
	if (dup2(out, STDOUT_FILENO) < 0)
		error_exit("dup2 for out failed", EXIT_FAILURE);
	while (i < ac - 2)
	{
		exec_child(av[i], envp);
		i++;
	}
	exec_cmd(av[i], envp);
	close(in);
	close(out);
	exit(EXIT_SUCCESS);
}