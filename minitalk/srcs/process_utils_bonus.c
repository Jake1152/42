/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:03:25 by jim               #+#    #+#             */
/*   Updated: 2022/03/01 16:30:27 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication_bonus.h"

void	sigaction_init(void (*handler))
{
	t_sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_handler("sigemptyset setting Error\n");
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		error_handler("sa_mask SIGUSR1 setting Error\n");
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("sa_mask SIGUSR2 setting Error\n");
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		error_handler("sigaciton SIGUSR1 setting Error\n");
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		error_handler("sigaciton SIGUSR2 setting Error\n");
}

int	pid_valider(pid_t pid)
{
	if (pid < 101 || pid > 99999)
		return (-1);
	return (1);
}
