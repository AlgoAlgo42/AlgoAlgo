import sys
N, M = map(int,sys.stdin.readline().split())
friends = set([])
for i in range(M):
    a,b = map(int, sys.stdin.readline().split())
    if min(a,b) == b:
        a, b = b, a
    friends.add(tuple([a,b]))

def recur(cnt, end, i, check):
    global minnum
    if end in r[i]:
        cnt += 1
        minnum = min(cnt, minnum)
        return
    
    for num in r[i]:
        if num not in check:
            check.append(num)
            recur(cnt+1, end, num, check[:])
            check.pop()


r = [[] for _ in range(N + 1)]
for f in friends:
    r[f[0]].append(f[1])
    r[f[1]].append(f[0])

minbacon = float('inf')
minbaconi = 0

for i in range(1, N+1):
    tmp = 0
    for j in range(1, N+1):
        if i == j:
            continue
        minnum = float('inf')
        recur(0, j, i, [])
        tmp += minnum
    if minbacon > tmp:
        minbaconi = i
        minbacon = tmp

print(minbaconi)