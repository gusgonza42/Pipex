/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:33:03 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/12 13:33:06 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include <sys/wait.h>

int main (int ac, char **av, char **envp)
{
    (void) av;
    (void) envp;
    (void) ac;
    if (ac != 5)
    {
        ft_printf("error need %d arg\n", 4);
        return (1);
    }
    int fd;
    fd = open(av[1], O_RDONLY);
    ft_printf("%d\n", fd);
    pid_t pid;
    pid = fork();
    execve("/bin/lss", (char *[]){"/bin/ls", NULL}, NULL);
    ft_printf("%d\n", fd);
    return (0);
}
