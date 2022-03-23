import sys

N, M = map(int, sys.stdin.readline().split())
arr = []
for _ in range(N):
    arr.append(sys.stdin.readline().rstrip())

answer = 1
for i in range(N):
    for j in range(M):
        num = arr[i][j]
        len = 0
        for idx in range(j+1, M):
            if arr[i][idx] == num:
                len = idx - j
                if i + len < N:
                    if arr[i+len][j] == num and arr[i+len][j+len] == num:
                        answer = max(answer, (len+1)*(len+1))
print(answer)