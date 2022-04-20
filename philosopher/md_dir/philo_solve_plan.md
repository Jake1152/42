# philo 문제해결과정 서술 18MAR22


- 철학자는 n명
- 포크는 n개
- 한번 식사할때 1명당 포크는 2개가 쓰인다.
- 가급적 다음순번이 누구인지 계산하는 과정없이
	바로 다음순번이 식사를 할수 있게해야 지연시간이 줄어서 스레드가 늘어나더라도 밀리거나 예기치 못한 동작이 없어진다.
- 입력값은 철학자 수, 식사 못하면 죽는시간, 식사시간, 자는시간, [최소먹어야하는 시간]
	- 입력값에 파싱처리
	- atoi 안되는 경우는 error 발생시킬것
- 철학자별 실행동작 코딩
	- 식사, 수면, 생각
	- 포크사용 가능여부 표현
		- 이 부분을 mutex 공유자원 표현
	- 출력하는 부분도 mutex로 해야만하는지 고려 필요
- 다 먹었는지, 지금 못먹으면 죽는지 확인하는 모니터 스레드 필요

-

- 구조체에 담을것은 무엇인가?
	- 포크 수
		- malloc
	-