/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:28:39 by jim               #+#    #+#             */
/*   Updated: 2022/05/16 14:38:10 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_status	status_info;

	if (argc < 5 || argc > 6)
	{
		print_notice();
		return (0);
	}
	if (init(argc, argv, &status_info) == FALSE)
		return (1);
	if (create(&status_info) == FALSE)
		return (1);
	monitoring(&status_info);
	if (join(&status_info) == FALSE)
		return (1);
	free_and_destory(&status_info, status_info.philosopher_cnt - 1, \
									status_info.philosopher_cnt - 1, \
									status_info.philosopher_cnt - 1);
	return (0);
}
