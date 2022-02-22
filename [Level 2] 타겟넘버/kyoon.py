def solution(numbers, target):
	def calculate(idx, sum):
		res = 0
		if idx == len(numbers):
			res = 0
			if sum == target:
				res += 1
			return res
		
		res += calculate(idx + 1, sum + numbers[idx])
		res += calculate(idx + 1, sum - numbers[idx])
		return res

	answer = calculate(0, 0)
	return answer