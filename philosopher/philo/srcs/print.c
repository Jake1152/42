/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:44:06 by jim               #+#    #+#             */
/*   Updated: 2022/04/21 16:44:06 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    print_notice(void)
{
    printf("please input appropriate value as argument,\n\
It will be only taked 4~5 argumentes.\n\
e.g)\n\
./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep number_of_times_each_philosopher_must_eat\n");
}

void	print_error(char *msg)
{
	printf("%s\n", msg);
}
