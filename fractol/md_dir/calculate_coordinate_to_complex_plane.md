# calculate_coordinate_to_complex_plane
- 무엇을 하는가?
	픽셀 좌표값을 Fractol 도형을 그릴 수 있도록 복소평면상의 좌표로 변환한다.
	- 복소평면의 전체크기와 window의 사이즈를 알아야한다.
	- 복소평면의 전체사이즈는 내가 정해주면 된다.
		- 이 또한 define을 쓸것인가?
		- 아니라면 enum을 쓰거나할수 있다.
		- 그렇게 된다면 계속 가지고 다녀야한다.
			- 언제 가지고 다녀야하는가?
			- calculate할때
				- zoom in, out
				- mouse point 클릭
	- zoom in, out, mouse pointer 위치에 따른 변환을 고려해야 하는가?
	- 변환한 값을 어떻게 전달할 것인가?
		- pointer로 접근하여 원본을 바꾼다.
		- t_coordinates으로 반환만한다.

- 무엇이 필요한가?
	- 좌표 구조체
	- window사이즈 (window사이즈는 rendering될 image이 사이즈와 동일하다.)
		- window 사이즈를 어떻게 처리하는게 나을것인가?
			- 낫다의 기준은 무엇인가?
				- 관리하기 편리하고 로직상 에러가 발생확률이 적은 방향, 일관성
			1. #define으로 정의
				처음에 접근하기 용이
				메모리상에 상주
				어느위치인가?
				data, stack, heap, text

				#define x -> 10
				전처리되는것은 메모리상에 남아있지 않다.
				enum 도 남아있지않다.
				상수로 처리

			2. enum 사용
				enum이 define보다 장점이 있던점이 있었는데 추가확인 필요
				계속 그 값을 인자로 넘겨줘야하는 단점이 있다.
			3. argv로 입력받음
				argv값을 체크 필요
				argv에 window사이즈를 넣지 않은 경우 default 값으로 실행되게할 필요가 있다.
