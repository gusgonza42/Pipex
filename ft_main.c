/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:33:03 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/17 14:08:27 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errors_arg(int error)
{
	write(2, "Arg; Error\n", 11);
	exit(error);
}

void	ft_errors(char *str, int error)
{
	perror(str);
	exit(error);
}

char	**ft_get_path(char **e, t_pipex pipex)
{
	char	**res;
	int		i;

	i = -1;
	while (e[++i] && ft_strncmp("PATH=", e[i], 4))
	{
		if (!e[i + 1])
			ft_errors(e[i], 1);
	}
	res = ft_split(e[i], ':');
	*res += 5;
	return (res);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		ft_errors_arg(142);
	pipex.paths = ft_get_path(envp, pipex);
	pipex.infd = open(av[1], O_RDONLY);
	if (pipex.infd == -1)
		perror(av[1]);
	pipex.outfd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfd == -1)
		perror(av[ac - 1]);
	if (pipe(pipex.pipe_fd) == -1)
		ft_errors("pipe", 1);
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		first_child(pipex, av, envp);
	pipex.p_id_2 = fork();
	if (pipex.p_id_2 == 0)
		second_child(pipex, av, envp);
	waitpid(pipex.p_id, NULL, 0);
	waitpid(pipex.p_id_2, NULL, 0);
	close(pipex.infd);
	close(pipex.outfd);
	return (0);
}
