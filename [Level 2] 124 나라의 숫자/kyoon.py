def solution(n):
	answer = ""
	num = []
	while n > 0:
		chk = False
		if n % 3 == 1:
			num.append("1")
		elif n % 3 == 2:
			num.append("2")
		else:
			num.append("4")
			chk = True
		n = int(n / 3)
		if chk:
			n -= 1
	for i in range(len(num)):
		answer += num.pop()
	return answer

n = 10
print(solution(1))