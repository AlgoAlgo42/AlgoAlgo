def solution(maps):
    answer = -1
    cnt = 0
    queue = [(0,0)]
    n, m = len(maps) - 1, len(maps[0]) - 1
    while not queue == []:
        cnt += 1
        l = len(queue)
        for i in range(l):
            x, y = queue.pop(0)
            if x == n and y == m:
                answer = cnt
                queue = []
                break
            if x < n and maps[x + 1][y] == 1:
                maps[x+1][y] = 2
                queue.append((x+1, y))
            if y < m and maps[x][y + 1] == 1:
                queue.append((x, y+1))
                maps[x][y+1] = 2
            if x > 0 and maps[x-1][y] == 1:
                queue.append((x-1, y))
                maps[x-1][y] = 2
            if y > 0 and maps[x][y-1] == 1:
                queue.append((x, y-1))
                maps[x][y-1] = 2
    return answer
