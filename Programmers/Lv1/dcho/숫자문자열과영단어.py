def solution(s: str) -> int:
	numList: dict = {'zero': 0,
			'one': 1,
			'two': 2,
			'three': 3,
			'four': 4,
			'five': 5,
			'six': 6,
			'seven': 7,
			'eight': 8,
			'nine': 9}
	answer: str = ''
	temp: str = ''
	for value in s:
		if value.isdigit():
			answer = answer + value
		elif value.isalpha():
			temp = temp + value
			if temp in numList.keys():
				answer = answer + str(numList[temp])
				temp = ''
	return int(answer)
