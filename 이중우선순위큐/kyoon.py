import sys, heapq

T = int(sys.stdin.readline().rstrip())
maxheap = []
minheap = []

for _ in range(T):
	N = int(sys.stdin.readline().rstrip())
	maxheap = []
	minheap = []
	visited = [False for _ in range(N)]

	for j in range(N):
		command = sys.stdin.readline().split()
		num = int(command[1])
		if command[0] == "I":
			heapq.heappush(maxheap,(-1*num, j))
			heapq.heappush(minheap,(num, j))
			visited[j] = True
		else:
			if num == -1:
				while minheap and not visited[minheap[0][1]]:
					heapq.heappop(minheap)
				if minheap:
					visited[minheap[0][1]] = False
					heapq.heappop(minheap)
			else:
				while maxheap and not visited[maxheap[0][1]]:
					heapq.heappop(maxheap)
				if maxheap:
					visited[maxheap[0][1]] = False
					heapq.heappop(maxheap)
		while maxheap and not visited[maxheap[0][1]]:
			heapq.heappop(maxheap)
		while minheap and not visited[minheap[0][1]]:
			heapq.heappop(minheap)

	if minheap and maxheap:
		print(-1 * maxheap[0][0], minheap[0][0], sep=" ")
	else:
		print("EMPTY")