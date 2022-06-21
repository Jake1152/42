/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:31:44 by jim               #+#    #+#             */
/*   Updated: 2022/06/18 19:06:37 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_struct.h"
#include "utils.h"

static char	**find_path_list(char **envp)
{
	char	*path;

	path = NULL;
	while (*envp && path == NULL)
	{
		path = ft_strnstr(*envp, "PATH", ft_strlen("PATH="));
		envp++;
	}
	if (path == NULL)
		return (NULL);
	path += sizeof(char) * ft_strlen("PATH=");
	return (ft_split(path, ':'));
}

static int	preprocess_path_cmd(char ***path_list, char ***cmd, char **envp, \
						char *argv)
{
	*path_list = find_path_list(envp);
	if (*path_list == NULL)
		return (ERROR);
	*cmd = ft_split(argv, ' ');
	if (*cmd == NULL)
	{
		free_list(&path_list);
		return (ERROR);
	}
	return (SUCCESS);
}

int	execute_cmd(char **envp, char *argv)
{
	char	**cmd;
	char	*cmd_path;
	char	**path_list;
	char	*path_with_slash;
	size_t	idx;

	if (preprocess_path_cmd(&path_list, &cmd, envp, argv) == ERROR)
		return (ERROR);
	idx = 0;
	while (path_list[idx])
	{
		path_with_slash = ft_strjoin(path_list[idx], "/");
		cmd_path = ft_strjoin(path_with_slash, cmd[0]);
		safe_free(&path_with_slash);
		execve(cmd_path, cmd, envp);
		safe_free(&cmd_path);
		idx++;
	}
	// local일때도 실행될 수 있어서 그 경우에 대한 대비 필요 cat etc..
	execve(cmd[0], cmd, envp);
	free_list(&cmd);
	free_list(&path_list);
	return (FAIL);
}
