/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:33:03 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/17 12:34:48 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//buscamos la variable de entorno  para devolver justo despues del =
//entonces tenemos las rutas del sistema

int main (int ac, char **av, char **envp)
{
	t_pipex pipex;
	/*char    *cmd = "/bin/ls";
	char    *cmds[] = {"/bin/ls", "-la", NULL};
	char    *cmd2 = "/bin/wc";
	char    *cmds2[] = {"/bin/wc", "-l", NULL};*/
   
	if (ac != 5)
		return (mssg("Invalid number of arguments"));

	if (pipe(pipex.pipe_fd) == -1)
		return (EXIT_FAILURE);
	//aqui tendria que ir el path osea la estructura debe tener un char *path?
	//aqui tendri que ir el cmd_path con el split osea loq ue tenemos con el pat enviarlo al split
	//u que lo divida por :
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		f_child_process(pipex, av, cmd, cmds, envp);
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
	}
	return (0);
}
