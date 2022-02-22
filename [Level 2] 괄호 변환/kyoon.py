def solution(p):
	answer = ''
	def recur(str):
		if str == "":
			return ""

		l = 0
		r = 0
		for i in range(len(str)):
			if str[i] == '(':
				l += 1
			else:
				r += 1
			if l == r:
				break

		u = str[0:i+1]
		v = recur(str[i+1:len(str)])

		if check(u):
			return u + v
		else:
			res = '(' + v + ')'
			u = u[1:len(u) - 1]
			for c in u:
				if c == '(':
					res += ')'
				else:
					res += '('
			return res

	def check(str):
		l = 0
		r = 0
		for c in str:
			if c == '(':
				l += 1
			else:
				r += 1
			if r > l:
				return False
		return True

	answer = recur(p)
	return answer