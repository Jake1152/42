# 전체 뼈대

- 1. 실행 (인자 값과 함께)
	- 1. 인자값 체크
		- 없으면 display
	- 2. 인자에 맞게 변환
		- 어떤 Fractal인지 확인
		- 숫자이면 정수 혹은 실수형으로 변환(실수형으로만 변환)
	- 3. Graphic 관련 init
		- mlx
		- window
		- image
	- 4. Fractal 그릴 수 있게 인자 넘겨주기

- 2. Fractal 그리기
	- 전달받은 Fractal을 그린다.
		- 점화식을 기준으로 그린다.
		- 특정 기준값을 넘어가는지 여부에 따라 수렴 발산 따진다.
		- 수렴하는 것들만 집합에 들어간다.
			- 집합에 들어가는 것들이 경계선이다.
	- 처음에는 경계선만 특정 색상으로 그린다.
	- 경계값을 초과하는지는 어떻게 아는가?
	- 어느정도 속도로 발산하는지는 어떻게 표현하는가?
	- 색상의 변화를 주는것은 어떻게 할 것인가?
	-

- 3. Event
	- loop hook
		- 계속 깊이를 쌓아나아간다.
	- Key Event
		- ESC
			- exit()
			- mlx_destory()
				- exit()과의 차이점
				- mlx, window, image 모두 메모리에서 제거해야한다.
	- mouse event
		- wheel
			- 배율을 어떻게 할 것인가?
			- 증감되어야한다.
			- 배율관련해서는 pointer로 구현한다.
				- coordinates는 pointer
			- up,
				- up하면 확대
			- down
				- 축소
		- click or mouse pointed
			- 마우스가 있는 지점 혹은 마우스가 클릭한 지점을 기준으로 확대축소를 진행한다.
			- 현재 위치를 기준
			- 배율을 어떻게 할 것인가?


