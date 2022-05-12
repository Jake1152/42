/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:59:41 by jim               #+#    #+#             */
/*   Updated: 2022/05/12 19:36:24 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error_handler(char *error_statement)
{
	/*
		-
		-
		-
	*/
	printf("%s\n", error_statement);
	return (1);
}

void    print_notice(void)
{
    printf("please input appropriate value as argument,\n\
It will be only taked 4~5 argumentes.\n\
e.g)\n\
./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep number_of_times_each_philosopher_must_eat\n");
}
