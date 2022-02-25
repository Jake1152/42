/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_communication.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:37:03 by jim               #+#    #+#             */
/*   Updated: 2022/02/25 19:11:57 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_COMMUNICATION_H
# define PROCESS_COMMUNICATION_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

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
/* process utils */
void	sigaction_init(void (*handler));
int		pid_valider(pid_t pid);
/* utils */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_putnbr_fd(int n, int fd);
/* error handler */
void	error_handler(char *error_sentence);

#endif
