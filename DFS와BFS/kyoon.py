import sys
from collections import deque

N, M, V = map(int, sys.stdin.readline().split())
graph = [[0 for _ in range(N+1)] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
d_answer = []
b_answer = []
for _ in range(M):
    i, n = map(int, sys.stdin.readline().split())
    graph[i][n] = 1
    graph[n][i] = 1

def dfs(idx):
    global visited
    if 0 not in visited[1:]:
        return
    visited[idx] = 1
    d_answer.append(str(idx))
    for node in range(1, N+1):
        if graph[idx][node] == 1 and visited[node] == 0:
            dfs(node)

def bfs(V):
    visited = [0 for _ in range(N+1)]
    queue = deque()
    queue.append(V)
    visited[V] = 1
    while queue:
        now = queue.popleft()
        b_answer.append(str(now))
        for node in range(1, N+1):
            if graph[now][node] == 1 and visited[node] == 0:
                queue.append(node)
                visited[node] = 1
dfs(V)
bfs(V)
print(' '.join(d_answer))
print(' '.join(b_answer))