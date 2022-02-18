/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:39:33 by jim               #+#    #+#             */
/*   Updated: 2022/02/18 17:52:54 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	/*
		TODO
		- server는 ctrl+c가 있기 전까지는 계속 떠있어야한다.
		- client로부터 PID와 메시지를 받는다.
		- 동시에 client로부터 입력 및 신로성있는 처리를 하는지 모른다.
		  아마 이 과제에서는 그렇게까지는 안하는것 같다.
		  signal 내부적으로 동시접속 및 신뢰성있게 처리해줄 수 있을 거 같다.
		Progress
		- Server run
		- Server waiting to connect from some client
		- PID, message(signal?) receive
		Curious
		- Unicode 2~4byte라는데 ASCII와 구분을 어떻게하는가?
		- write함수에서 알수 있는 방법이 있는가?
		
	*/
	return (0);
}
