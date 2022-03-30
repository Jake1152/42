- greedy && LIS way

1. stack a에 있는 값들을 LIS를 통해 LIS에 해당하지 않는 값들만 stack b로 넘긴다.
	- 넘길때 pivot개념을 쓰면 최적화 할 수 있을 것 같다.
	- stack a에 LIS인것을들 남길때 어떻게 순서를 유지해서 남길것인가?
		- 상대적 크기순서를 저장한다
		- 저장하지 않고 하는 방법이 있는가?
		- LIS 아닌것들만 넘길때도 최적화 할 수 있는가?
			- 이떄도 greedy를 쓴다?
		- LIS인지 아닌지 flag

2. 그 순간에 stack b에서 stack a로 넘기기 위해 명령어를 써야하는 개수를 모든 element에 대해서 카운팅한 뒤에 가장 적은 명령어가 소요되는 element를 stack a로 넘겨준다.
	- 이 부분에서 최적화할 수 있는 요소가 있기는하다.
	- deeplearning을 쓸 수 있는가?

3.

4.

5.

