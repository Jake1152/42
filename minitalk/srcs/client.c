/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:30 by jim               #+#    #+#             */
/*   Updated: 2022/02/19 21:40:17 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

int	client(void)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	long long	received_sig;
	int			pid;

	if (argc != 3)
		print_error();
	pid = ft_atoi(argv[1]);
	if (ft_strncmp(argv[1], "0", 1) != 0 && pid == 0)
		print_error();
	kill(pid, SIGUSR1);
	argv[2];
}


int main(int argc, char *argv[])
{
    char            *str;
    unsigned int    flag;
    pid_t           server_pid;
    size_t          idx;

    str = "Hello world";
    idx = 0;
    
    if (argc != 2)
    {
        printf("non invalid argument.\n");
        exit(EXIT_FAILURE);
    }
    server_pid = atoi(argv[1]);
    while (str[idx])
    {
        printf("char : %c\n", str[idx]);
        printf("char in dec : %d\n", str[idx]);
        flag = 1 << 7;
        while (flag)
        {
            printf("str[idx] & flag : %d\n", str[idx] & flag);
            if (str[idx] & flag)
                kill(server_pid, SIGUSR1);
            else
                kill(server_pid, SIGUSR2);
            flag >>= 1;
        }
        whukle
        flag 
        printf("char : %du\n", flag);
        idx++;
    }
    return (0);
}
