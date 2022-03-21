import sys
sys.setrecursionlimit(10**9)

N, r, c = map(int, sys.stdin.readline().split())

def find(i, j, n):
    if 0 <= i and i < 2**(n-1) and 0 <= j and j < 2**(n-1):
        return 1
    if 0 <= i and i < 2**(n-1) and 2**(n-1) <= j and j < 2**(n):
        return 2
    if 2**(n-1) <= i and i < 2**(n) and 0 <= j and j < 2**(n-1):
        return 3
    if 2**(n-1) <= i and i < 2**(n) and 2**(n-1) <= j and j < 2**(n):
        return 4

def relocate(i, j, loc, n):
    if loc == 2:
        j -= 2**(n-1)
    elif loc == 3:
        i -= 2**(n-1)
    elif loc == 4:
        i -= 2**(n-1)
        j -= 2**(n-1)
    return i, j

def recur(cnt, n, r, c):
    loc = find(r, c, n)
    cnt += 2**(n-1) * 2**(n-1) * (loc - 1)
    if n == 1:
        return cnt

    r, c = relocate(r, c, loc, n)
    return recur(cnt, n-1, r, c)

print(recur(0, N, r, c))