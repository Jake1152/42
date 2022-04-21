/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:08:21 by jim               #+#    #+#             */
/*   Updated: 2022/04/21 19:58:41 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>

// int	gettimeofday(struct timeval *tp, void *tzp);
// int	main(struct timeval *tp, void *tzp)
int	main(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	// tz ==> time zone 현재는 안쓰이며 앞으로도 안쓰일것이라고 한다.
	// https://www.joinc.co.kr/w/man/2/gettimeofday
	printf("Time(sec) : %d\n", (int)tv.tv_sec);
	printf("TIme(micro_sec : %d\n", (int)tv.tv_usec);
	return (0);
}
