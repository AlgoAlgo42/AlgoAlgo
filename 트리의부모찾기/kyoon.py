import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(N+1)]
parent = [[] for _ in range(N+1)]
for _ in range(N-1):
    n1, n2 = map(int, sys.stdin.readline().split())
    graph[n2].append(n1)
    graph[n1].append(n2)
check = [0 for _ in range(N+1)]
que = deque()
que.append((1,0))
check[1] = 1
while que:
    now, p = que.popleft()
    check[now] = 1
    parent[now] = p
    for node in graph[now]:
        if check[node] == 0:
            que.append((node, now))

for i in range(2, N+1):
    print(parent[i])