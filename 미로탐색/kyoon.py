import sys
from collections import deque
si = sys.stdin.readline

N, M  = map(int, si().split())

miro = []
for _ in range(N):
    miro.append(si().rstrip())

check = [[0 for _ in range(M)] for _ in range(N)]

queue = deque()
queue.append((0,0,0))
check[0][0] = 1

while queue:
    q = queue.popleft()
    i = q[0]
    j = q[1]

    if i == N-1 and j == M-1:
        break
    if i+1<N and miro[i+1][j] == "1" and check[i+1][j] == 0:
        queue.append((i+1,j,q[2]+1))
        check[i+1][j] = 1
    if j+1<M and miro[i][j+1] == "1" and check[i][j+1] == 0:
        queue.append((i,j+1,q[2]+1))
        check[i][j+1] = 1
    if 0 <= i-1 and miro[i-1][j] == "1" and check[i-1][j] == 0:
        queue.append((i-1,j,q[2]+1))
        check[i-1][j] = 1
    if 0 <= j-1 and miro[i][j-1] == "1" and check[i][j-1] == 0:
        queue.append((i,j-1,q[2]+1))
        check[i][j-1] = 1

print(q[2] + 1)