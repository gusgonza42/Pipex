/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:33:03 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/14 18:12:01 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//buscamos la variable de entorno  para devolver justo despues del =
//entonces tenemos las rutas del sistema
/*char	*finder_path(char **envp)
{
	while (ft_strcmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5)
}*/

int main (int ac, char **av, char **envp)
{
	t_pipex pipex;
	char    *cmd = "/bin/ls";
	char    *cmds[] = {"/bin/ls", "-la", NULL};
	char    *cmd2 = "/bin/wc";
	char    *cmds2[] = {"/bin/wc", "-l", NULL};
   
	/*if (ac != 5)
		return (mssg("Invalid number of arguments"));
*/
	if (pipe(pipex.pipe_fd) == -1)
	{
		return (EXIT_FAILURE);
	}
	//tengo se comporta como una pipe
	//aqui tendria que ir el path osea la estructura debe tener un char *path?
	//aqui tendri que ir el cmd_path con el split osea loq ue tenemos con el pat enviarlo al split
	//u que lo divida por :
	pipex.p_id = fork();
	if (pipex.p_id == 0)
	{
		//f_child_process(pipex, cmd, cmds, envp);
	//hijo se ejecuta los comandos
		pipex.infd = open(av[1], O_RDONLY);//esto pa leer
		if (pipex.infd == -1)
			return (EXIT_FAILURE);
		dup2(pipex.infd, STDIN_FILENO);//se comporta como STDIN EL INFD pero
		dup2(pipex.pipe_fd[1], STDOUT_FILENO);//envia

		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		close(pipex.infd);
		execve(cmd, cmds, envp);//ejecta comandos y hace exit si el comando funciona 
		
	}
	else if (pipex.p_id > 0)
	{
		//papa aqui espra a que el hijo acabe
		pipex.p_id_2 = fork();
		if (pipex.p_id_2 == 0)
		{
			//hijo  outfile
		//	f_child_process(pipex, cmd2, cmds2, envp);
		
			pipex.outfd = open("res", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(pipex.pipe_fd[0], STDIN_FILENO);//
			dup2(pipex.outfd, STDOUT_FILENO);//SE COMPORTA COMO EL STOUT que redirige la salida al outfile  
			close(pipex.pipe_fd[0]);
			close(pipex.pipe_fd[1]);
			close(pipex.infd);
			close(pipex.outfd);
			execve(cmd2, cmds2, envp);//ejecta comandos y hace exit si el comando funciona 
		
		}
		else if (pipex.p_id_2 > 0)
		{
		    //papa
			close(pipex.pipe_fd[0]);
			close(pipex.pipe_fd[1]);
			waitpid(pipex.p_id, 0, 0);//sspera al hijo1
			waitpid(pipex.p_id_2, 0, 0);//espera al hijo2 yya
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
	}
	return (0);
}
