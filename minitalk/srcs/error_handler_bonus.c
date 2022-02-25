/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:16:18 by jim               #+#    #+#             */
/*   Updated: 2022/02/25 17:55:50 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_communication.h"

void	error_handler(char *error_sentence)
{
	ft_putstr_fd(error_sentence, 2);
	exit(EXIT_FAILURE);
}
