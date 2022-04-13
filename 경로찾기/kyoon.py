import sys
sys.setrecursionlimit(10**9)
si = sys.stdin.readline

n = int(si().rstrip())

arr = []
for _ in range(n):
    arr.append(list(si().split()))


answer = [["0" for _ in range(n)] for _ in range(n)]

def recur(start, node):
    global check, answer
    for i in range(n):
        if arr[node][i] == "1" and check[i] == 0:
            check[i] = 1
            answer[start][i] = "1"
            recur(start, i)

for i in range(n):
    if "1" in arr[i]:
        check = [0 for _ in range(n)]
        recur(i, i)

for i in range(n):
    print(" ".join(answer[i]))