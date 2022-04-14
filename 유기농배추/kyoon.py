import sys
sys.setrecursionlimit(10**9)
def recur(i, j, field):
    field[i][j] = 0
    if 0 <= i-1 and i < N and field[i-1][j] == 1:
        recur(i-1,j,field)
    if 0 <= i+1 and i+1 < N and field[i+1][j] == 1:
        recur(i+1,j,field)
    if 0 <= j-1 and j < M and field[i][j-1] == 1:
        recur(i,j-1,field)
    if 0 <= j+1 and j+1 < M and field[i][j+1] == 1:
        recur(i,j+1,field)

T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    field = [[0 for _ in range(M)] for _ in range(N)]

    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        field[y][x] = 1
    cnt = 0
    for n in range(N):
        for m in range(M):
            if 1 not in field[n]:
                break
            if field[n][m] == 1:
                cnt += 1
                recur(n, m, field)
    print(cnt)