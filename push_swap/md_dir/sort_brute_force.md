# bruteforce same and under 5 elements

- 2개 일때
	- swap만하면 된다.
		- 이유는 이미 정렬이 되었는지 확인해서
		- 정렬되지 않은 것들만 넘겨주므로 swap으로 해결가능!

- 3개 일때
	3! = 6개, 정렬된것 제외하면 5개
	1	2	2	3	3
	3	3	1	2	1
	2	1	3	1	2

	rr	rr	sw	sw	r
	sw			rr

	mid를 기준으로 체크?
	mid를 알면 어떤게 min, max인지 알 수 있다.
	3개 값이 있을때 mid값을 찾는 방법
	a, b, c
	1 3 2 rr
	2 3 1 rrr
	2 1 3 rb
	3 2 1
	3 1 2

	if (a > b || a > c && a < b || a < c)


- 4,5개 일때
-
