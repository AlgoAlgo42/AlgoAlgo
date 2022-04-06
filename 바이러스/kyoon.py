import sys
from collections import deque
si = sys.stdin.readline

N = int(si().rstrip())
t = int(si().rstrip())
tree = [[] for _ in range(N)]
check = [0 for _ in range(N)]
check[0] = 1
for _ in range(t):
    a, b = map(int, si().split())
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)
answer = -1

def recur(check, node):
    global answer
    answer += 1
    for i in tree[node]:
        if check[i] == 0:
            check[i] = 1
            recur(check, i)

recur(check, 0)
print(answer)