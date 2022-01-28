def solution(id_list, report, k):
	l = len(id_list)
	answer = [0 for i in range(l)]
	cnt = [0 for i in range(l)]
	dic = {}
	check = [[0 for i in range(l)] for j in range(l)]
	for i in range(0, l):
		dic[id_list[i]] = i

	for str in report:
		man = str.split(" ")
		if check[dic[man[1]]][dic[man[0]]] == 0:
			cnt[dic[man[1]]] += 1
			check[dic[man[1]]][dic[man[0]]] = 1
	for i in range(0, l):
		if cnt[i] >= k:
			for j in range(0, l):
				if check[i][j] == 1:
					answer[j] += 1				
	return answer