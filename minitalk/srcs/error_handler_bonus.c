/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:16:18 by jim               #+#    #+#             */
/*   Updated: 2022/02/26 19:03:41 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication_bonus.h"

void	error_handler(char *error_sentence)
{
	ft_putstr_fd(error_sentence, 2);
	exit(EXIT_FAILURE);
}
