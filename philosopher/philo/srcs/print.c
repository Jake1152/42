/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:26:38 by jim               #+#    #+#             */
/*   Updated: 2022/05/13 18:26:38 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

/*
- print statement로 관리
- mutex 변수를 포인터를 이용해서 넘겨받는다.
- print lock을 쓴다.
*/

int	print_error(char *error_statement)
{
	printf("%s\n", error_statement);
	return (TRUE);
}
