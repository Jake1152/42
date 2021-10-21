/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_with_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/10/21 17:07:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 32
#define FD_SIZE 256

char	*get_next_line(int fd)
{
	static char		*remain[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*new_line_str;
	char			*joined_str;
	int				read_str_len;
	size_t			new_line_idx;

	/* about fd handling
	 * fd 사이즈(file descriptor의 최대갯수)가 필요한 이유는 배열로 처리하기 떄문이다.
	 * fd를  읽을  수  없으면 -1일때 NULL Return
	 * 만약 fd가 open_max size가 넘어간다면? UNIX fd size가 256개이므로 그에 맞춰준다.
	 * window file handler랑 연동할 수 있는 방법이 있는가?
	 * unix계열인 linux에서도 에러없이 동작하도록 호환성있게 할려면 어떻게 해야하는가?
	 * 1. 최대 fd 갯수를 받아와서 지정해준다.
	 * 	- 허용하지 않는 함수를 쓰는거라 문제가 될 수 있다.
	 * 2. dynamic data set을 이용한다.
	 *  - linked list, tree
	 *  하지만 전체 함수 갯수가 10개라서 다 채울 수 있을지 모른다.
	 *  된다면 트리나 해쉬 구조를 쓰는게 효율적이라 생각
	 * 3. fd 값이 -1이 되기 전까지는 malloc을 통해서 fd_array 사이즈를 점점 늘린다.
	*/
	// ssize_t	 read(int, void *, size_t) __DARWIN_ALIAS_C(read);
	read_str_len = 0;
	remain[fd] = NULL;
	while (1)
	{
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		if (read_str_len <= 0)
			break ;
		// read_str_len = read(fd, str, BUFFER_SIZE);
		read_str[read_str_len] = '\0';
		remain[fd] = ft_strdup(""); // static 처음일때 초기화, 해당 fd에서 다른 문자열을 담는 메모리 공간을 가리킨다.
		// ft_strchr(str, '\n') 결과가 NULL 이어도 동작 가능, 
		// "abcde\n123"
		// 인덱스가 5일때 newline 0~5까지는 static이 가리키는 메모리의 문자열과 합쳐져서 반환되어야한다.
		new_line_idx = ft_strchr(read_str, '\n') - read_str;
		
		// ft_strchr로 \n을 찾았을때 동작
		// newline까지는 static과 strjoin, 이후 문자열('\0'직전까지)은 새롭게 strdup이후 static이 가리킴
		if (new_line_idx >= 0)
		{
			// new_line_str을 미리 초기화해서 넘겨야하는가? malloc해서 넘겨야한다.
			new_line_str = (char *)malloc(sizeof(char) * new_line_idx + 1 + 1);
			if (!new_line_str)
				return (NULL);
			// str[0:new_line_idx], ew_line_idx + 1 + 1 => idx 0부터 시작이라 1+, 뒤에 \0 들어가야해서 +1
			ft_strlcpy(new_line_str, read_str, new_line_idx + 1 + 1);
			
			// ft_strdup()
			// abasdg\n123
			// static에 저장한 문자열이 있을때
			if (remain[fd] != "")
			{
				// new_line_str은 개행부분까지 복사할 변수
				// *joined_str, joined_str 둘 중에 무엇?
				joined_str = ft_strjoin(remain[fd], new_line_str);
				// static도 join되었으니까 가리키던 메모리 free시킨다.
				free(remain[fd]);
				// static에 남은 부분 할당할 수 있게 빈공간 재할당
				remain[fd] = ft_strdup("");
				// remain 남는 부분 저장
				ft_strlcat(remain, &read_str[new_line_idx + 1], (read_str_len - (new_line_idx + 1)) + 1);
				//read에서 남은것은 이제 remain 저장해줘야한다.
				// free(remain[fd]); // free example
			}
			// static이 비어 있을때, read()를 통해 현재 읽은 \n까지 strdup해서 새로운 공간
			else
				joined_str = ft_strdup(new_line_str);
		}
		// static에 현재까지 읽은 문자열을 저장한다.
		else
		{
			// joined_str에 static에 있던것과 새로 read한것을 합친다.
			joined_str = ft_strjoin(remain[fd], new_line_str);
			// 기존 remain[fd]가 가리키던 메모리 공간을 free한다.
			free(remain[fd]);
			// 다시 *remain[fd]에서 합친 메모리공간을 가리키게한다.
			// 이게 가능한가?
			// 가리키던 공간을 free하고 다시 새로운 곳을 가리키니까 되는가?
			// remain[fd] = joined_str; 이것과의 차이는 무엇인가?
			remain[fd] = joined_str;
		}
		// joined_str에 담았으니까 개행까지 있던 것 따로 저장한 변수 new_line_str은 free
		free(new_line_str);
		return (joined_str);
		// printf("%s\n", str);
		// str에 \n이 있는 곳까지 읽는다.
	}
	//static true
	// 개행이 1개도 없는 경우 하지만 static에 읽은 문자들은 있을때 그것을 반환한다.
	// 그런데 따로 동적할당을 해줘야할 필요가 있는가?
	// static이 가리키던애를 그냥 넘겨주면 되는가?
	// static 초기화, static이 가리키는애를 초기화하니까 상관없나
	// static은 1번만 초기화된다.
	// 그건 다음 호출일때 이야기다.
	// 그렇다면 while문 안에서 재할당 해주는건 정상적으로 된다.
	if (remain[fd])
		return (remain[fd]);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (NULL);
}
