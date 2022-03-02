dic = {}

def combination(arr, chosen, l):
    if len(chosen) == l:
        str = ''.join(sorted(chosen))
        if str in dic:
            dic[str] += 1
        else:
            dic[str] = 1
        return
    
    start = arr.index(chosen[-1]) + 1 if chosen else 0
    for i in range(start, len(arr)):
        chosen.append(arr[i])
        combination(arr, chosen, l)
        chosen.pop()
    

def solution(orders, course):
    answer = []
    l = 0
    for s in orders:
        length = len(s)
        if length > l:
            l = length
    for i in course:
        if i > l:
            break
        for order in orders:
            if len(order) < i:
                continue
            combination(order, [], i)
        max = 2
        for j in range(len(orders), 2, -1):
            if j in dic.values():
                max = j
                break
        for d in dic.items():
            if d[1] == max:
                answer.append(d[0])
        dic.clear()       

    return sorted(answer)