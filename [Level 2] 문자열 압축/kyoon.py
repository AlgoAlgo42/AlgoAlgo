def numLength(n):
	res = 0
	while n:
		n //= 10
		res += 1
	return res - 1

def solution(s):
	l = len(s)
	answer = 0
	if l == 1:
		return 1
	for cut in range(1, l // 2 + 1):
		res = 0
		cnt = 1
		a = s[:cut]
		for i in range(cut, l, cut):
			if a == s[i:i+cut]:
				cnt += 1
			else:
				a = s[i:i+cut]
				if cnt > 1:
					res += 1 + cut
				else:
					res += cut
				if cnt >= 10:
					res += numLength(cnt)
				cnt = 1
		if cnt > 1:
			res += numLength(cnt)
		if cnt > 1:
			res += 1 + cut
		else:
			if l % cut == 0:
				res += cut
			else:
				res += l % cut
		if answer == 0 or answer > res:
			answer = res

	return answer