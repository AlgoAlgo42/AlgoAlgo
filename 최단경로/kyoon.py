import sys, heapq

V, E = map(int, sys.stdin.readline().split())
K = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(V)]
queue = []
INF = sys.maxsize
cnt = [INF for _ in range(V)]

for i in range(E):
	u, v, w = map(int, sys.stdin.readline().split())
	graph[u-1].append((v-1,w))

cnt[K-1] = 0
heapq.heappush(queue, (0, K-1))
while queue:
	wei, now = heapq.heappop(queue)
	if cnt[now] < wei:
		continue
	for n, w in graph[now]:
		nextwei = w + wei
		if nextwei < cnt[n]:
			cnt[n] = nextwei
			heapq.heappush(queue, (nextwei, n))

for i in cnt:
	print(i if i != INF else 'INF')