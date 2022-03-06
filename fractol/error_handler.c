/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:39:39 by jim               #+#    #+#             */
/*   Updated: 2022/03/03 17:41:37 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handler(char *error_sentence)
{
	ft_putstr_fd(error_sentence, 2);
	exit(EXIT_FAILURE);
}
