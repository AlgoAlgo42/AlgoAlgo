​

## Pseudo Code

```
	Initialize iterator: first, last, and target(cursor)
	target = first
	while (first != last) // 끝까지 반복
		++first // 1씩 증가
		if (target != first) // first의 값이 달라지면
			target++ // target 다음 값을 first로 변경
			change target to first

	return count of nums;

```

## 도출 과정

-   반복문 두개로 하려고 했지만 비효울적인것 같아서
-   반복문 하나에 값 변경과 이터레이팅을 동시에 할 수 있을 것 같아서
-   변수를 하나 더 두고 변경되야 하는 위치를 가르키게 했다.
