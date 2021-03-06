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

- 구조체에 담을것은 무엇인가?
	- 포크 수
		- malloc
	-

## 과정
- 0. 식사순서 정할것
	starvation, deadlock, mutual exclusion 만족 및 효율적인 구조
	- starvation이 확실하게 방지될지는 모르겠다.
	- 우선 대략적인 틀이 나왔으므로 구현한다.
		- 홀수는 왼쪽 잡고 오른쪽을 잡는다.
		- 짝수는 오른쪽을 먼저잡고 왼쪽을 잡는다.
- 1. parsing, error handling, init
	- struct
		구조체 멤버변수는 어떻게 가져갈 것인가?
		- 어떤식으로 구조를 짜는지에 따라 달라진다.
		- 고려사항이 어떻게 되는가?
			- 철학자가 기아상태로 죽으면 멈추고 종료되어야한다.
				- 다른 스레드들이 그 사이에 동작되어서는 안된다.
				- 즉 모두가 살았는지에 대한 lock이 필요하다.
					- 그러면 다른 철학자가 죽었는지 살았는지에 대한 정보가 되어서 과제 조건에 나온 정보를 알아서는 안된다는 부분에 저촉된다.
					- 다른 표현을 적더라도 결국 다른 철학자의 생존여부를 의미하는것이 아닌가?
					- 철학자 구조체에서만 접근하지 못하게하면 되는것인가?
					- 철학자 구조체 멤버변수로 필요한 것은 무엇인가?
						- 구조체의 멤버변수를 정하기 위해 필요한 선정조건은 어떻게 되는가?
							- 어떤 동작을 하는가?
							- 동작별로 필요한 상태는 무엇인가?
							- 그외에 고려할 부분은 어떻게 되는가?

- 2. implementation
- 3. execute
