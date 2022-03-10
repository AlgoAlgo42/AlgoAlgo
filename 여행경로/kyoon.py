answer = []

def recur(tickets, route, check, l):
    if 0 not in check:
        answer.append(route)
        return

    for i in range(l):
        if check[i] == 0 and tickets[i][0] == route[-1]:
            check[i] = 1
            route.append(tickets[i][1])
            recur(tickets, route[:], check, l)
            check[i] = 0
            route.pop()


def solution(tickets):
    l = len(tickets)
    check = [0 for _ in range(l)]
    
    for i in range(l):
        if tickets[i][0] == "ICN":
            check[i] = 1
            recur(tickets, [tickets[i][0], tickets[i][1]], check, l)
            check = [0 for _ in range(l)]
    
    if len(answer) > 1:
        answer.sort()
    return answer[0]