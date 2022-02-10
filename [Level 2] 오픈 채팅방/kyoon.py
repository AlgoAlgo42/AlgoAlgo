def solution(record):
	answer = []
	dic = {}
	for str in record:
		info = str.split(" ")
		if info[0] == "Enter":
			if info[1] in dic.keys():
				dic[info[1]] = info[2]
			else:
				dic[info[1]] = info[2]
			answer.append(info[1] + "님이 들어왔습니다.")
				
		if info[0] == "Leave":
			answer.append(info[1] + "님이 나갔습니다.")

		if info[0] == "Change":
			dic[info[1]] = info[2]
	changeName(dic, answer)

	return answer

def changeName(dic, answer):
	for i in range(len(answer)):
		str = answer[i].split("님")
		answer[i] = dic[str[0]] + "님" + str[1]