/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:43:24 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/19 21:29:13 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_builtin(char **comm)
{
	static char	*builtins[8] = {"cd", "echo", "env", "export", "pwd", "unset",
		"exit", NULL};
	size_t		n;

	n = 0;
	while (builtins[n])
	{
		if (!ft_strncmp(builtins[n], comm[0], ft_strlen(builtins[n]) + 1))
			return (1);
		n++;
	}
	return (0);
}

int	exec_builtins(t_list *pipex, t_minishell *minishell, int *double_r)
{
	int				n;
	static char		*builtins[8] = {"cd", "echo", "env", "export", "pwd",
		"unset", "exit", NULL};
	static t_tabp	tab[7] = {builtin_cd, builtin_echo, builtin_env,
		builtin_export, builtin_pwd, builtin_unset, builtin_exit};
	char			**comm;

	n = 0;
	comm = ((t_content *)pipex->content)->comm;
	while (builtins[n])
	{
		if (!ft_strncmp(builtins[n], comm[0], ft_strlen(builtins[n]) + 1))
			break ;
		n++;
	}
	return (tab[n](comm, minishell, double_r));
}

void	error_exec(t_content *content, t_minishell *minishell, char *path)
{
	int	fd;

	execve(path, content->comm, minishell->env);
	if (content->comm[0][0] == '/')
	{
		fd = open(content->comm[0], O_DIRECTORY);
		if (fd == -1)
		{
			exec_error_print(
				"minishell: ", content->comm[0], ": No such file or directory");
			exit (127);
		}
		else
		{
			exec_error_print(
				"minishell: ", content->comm[0], ": Is a directory");
			close(fd);
			exit (126);
		}
	}
	exec_error_print("minishell: ", content->comm[0], ": command not found");
	exit(127);
}

int	error_exec_solo(t_content *content, t_minishell *minishell, char *path)
{
	int	fd;

	execve(path, content->comm, minishell->env);
	if (content->comm[0][0] == '/')
	{
		fd = open(content->comm[0], O_DIRECTORY);
		if (fd == -1)
		{
			exec_error_print(
				"minishell: ", content->comm[0], ": No such file or directory");
			return (127);
		}
		else
		{
			exec_error_print(
				"minishell: ", content->comm[0], ": Is a directory");
			close(fd);
			return (126);
		}
	}
	exec_error_print("minishell: ", content->comm[0], ": command not found");
	return (127);
}

void	exec_builtins_solo_bolo(
					t_minishell *minishell, int **pipes, int *pids, int *savefd)
{
	g_tab_flag[0] = exec_solo(*(minishell->list), minishell, pipes);
	free(pids);
	dup2(savefd[0], STDIN);
	dup2(savefd[1], STDOUT);
	return ;
}
