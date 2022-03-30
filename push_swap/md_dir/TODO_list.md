since 12JAN22, MD since 26MAR22

1. 문제이해
- 주어지는 숫자를 a stack으로 넣는다.
- b stack은 비어있다.
- 처음에 나오는 숫자가 top에 위치한다.
- a,b 2개의 stack과 11개의 명령어를 통해 해당 명령어를 가장 최소로 쓰고 정렬한다.
- 명령어를 쓸때마다 명령어를 print한다.
- bonus로 checker를 만들 수 있다.
	- 주어지는 mac checker와 동일하게 동작해야한다.

2. 문제 재정의
- 상동

3. 문제해결방법
- stack 자료구조 만들기
	- circular double linked list
- 11개 동작 구현
	- 노드를 떼어서 명령대로 옮긴다.
- parsing
	- isspace를 기준으로 나눈다.
	- " 3 5 7 5"같이 ""안에 오는 경우 ft_split을 쓴다.
	- 13 a 같이 들어오면 프로그램 종료 이후 ERROR 출력한다.
	- 13as24도 마찬가지로 프로그램 종료 이후 ERROR
	- int 범위 이내인 숫자만 처리해야한다.
		- int경계값에 대해서 처리한다.
- duplicate check
	- 중복체크하여 있으면 종료하고 ERROR 출력

- Sorting
	- Sorted인지 확인
		- ASC
		- DESC
	- 2, 3, 5개 일때 정렬
	- Recurrsive 이용
	- 하노이탑 느낌쓰
	- pivot을 3개로 나눈다.
	-

4. 검증


5. 실행


6. 회고

