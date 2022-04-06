import sys, math
N = int(sys.stdin.readline().rstrip())

s = str(math.factorial(N))
l = len(s)
cnt = 0
for i in range(l-1, 0, -1):
	if s[i] != "0":
		break
	else:
		cnt += 1
print(cnt)