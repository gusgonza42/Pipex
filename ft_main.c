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
//buscamos la variable de entorno  para devolver justo despues del =
//entonces tenemos las rutas del sistema

void  ft_errors_arg(int error)
{
	write	(2, "Arg; Error\n", 11);
	exit (error);
}

void ft_errors(char *str, int error)
{
	perror(str);
	exit (error);
}

char **ft_get_path(char **e, t_pipex pipex)
{
	char **res;
	int i;

	i = -1;
	while (e[++i] && ft_strncmp("PATH=", e[i], 4))
	{
			if (!e[i+1])
				ft_errors(e[i], 1);
	}
	res = ft_split(e[i], ':');
	*res += 5;
	return (res);
}
int main (int ac, char **av, char **envp)
{
	t_pipex pipex;
	/*char    *cmd = "/bin/ls";
	char    *cmds[] = {"/bin/ls", "-la", NULL};
	char    *cmd2 = "/bin/wc";
	char    *cmds2[] = {"/bin/wc", "-l", NULL};*/
   

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


	
	/*check_args(ac);
	if (pipe(pipex.pipe_fd) == -1)
		return (EXIT_FAILURE);
	//aqui tendria que ir el path osea la estructura debe tener un char *path?
	//aqui tendri que ir el cmd_path con el split osea loq ue tenemos con el pat enviarlo al split
	//u que lo divida por :
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		//f_child_process(pipex, av, cmd, cmds, envp);
		f_child_process(pipex, av, envp);
	else if (pipex.p_id > 0)
	{
		//papa aqui espra a que el hijo acabe
		pipex.p_id_2 = fork();
		if (pipex.p_id_2 == 0)
			//s_child_process(pipex, cmd2, cmds2, envp);
			s_child_process(pipex, av, envp);
		else if (pipex.p_id_2 > 0)
		{
		    //papa
			close(pipex.pipe_fd[0]);
			close(pipex.pipe_fd[1]);
			waitpid(pipex.p_id, 0, 0);//sspera al hijo1
			waitpid(pipex.p_id_2, 0, 0);//esp:x
										//era al hijo2 yya
		}
		else
		{
			close(pipex.pipe_fd[0]);
			close(pipex.pipe_fd[1]);
			return (EXIT_FAILURE);
		}    
	}
	else
	{
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		return (EXIT_FAILURE);
	}*/
	return (0);
}
