import sys
si = sys.stdin.readline

N = int(si().rstrip())
dp = [0 for _ in range(N)]

stairs = []
for _ in range(N):
    stairs.append(int(si().rstrip()))

dp[0] = stairs[0]
if N >= 2:
    dp[1] = stairs[0] + stairs[1]
if N >= 3:
    dp[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2])

for idx in range(3, N):
    dp[idx] = max(dp[idx-3] + stairs[idx-1], dp[idx-2]) + stairs[idx]

print(dp[N-1])