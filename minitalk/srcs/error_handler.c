/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:16:18 by jim               #+#    #+#             */
/*   Updated: 2022/02/23 12:32:40 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

void	error_handler(char *error_sentence)
{
	ft_putendl(error_sentence, 2);
	exit(EXIT_FAILURE);
}
