def solution(numbers):
	answer = 0
	chk = [0 for _ in range(10)]
	for num in numbers:
		chk[num] = 1
	for i in range (len(chk)):
		if chk[i] == 0:
			answer += i
	return answer