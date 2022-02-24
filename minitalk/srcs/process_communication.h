/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_communication.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:37:03 by jim               #+#    #+#             */
/*   Updated: 2022/02/19 21:39:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_COMMUNICATION_H
# define PROCESS_COMMUNICATION_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h> // shouldbe removed

// flag define
# define ON 1
# define OFF 0

typedef struct sigaction t_sigaction;
typedef struct  s_signal_status
{
	int	sig_receive_status;
	int	sig_send_status;
}				t_signal_status;

/* server */
void	sa_server_handler(int signo, siginfo_t *sig_info, void *ucontext);
void	server_bit_receiver(siginfo_t *sig_info);
int		server_bit_sender(pid_t client_pid, int send_flag);
/* client */
void	sa_client_handler(int signo, siginfo_t *sig_info, void *ucontext);
void	client_bit_receiver(siginfo_t *sig_info);
int 	string_sender(pid_t server_pid, char *str);
/* sigaction utils */
void	sigaction_init(void (*handler));
/* utils */
void	ft_putendl(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		pid_valider(pid_t pid);
/* error handler */
void	error_handler(char *error_sentence);

#endif
