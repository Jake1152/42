/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:06:14 by jim               #+#    #+#             */
/*   Updated: 2022/02/26 19:06:16 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

void	error_handler(char *error_sentence)
{
	ft_putstr_fd(error_sentence, 2);
	exit(EXIT_FAILURE);
}
