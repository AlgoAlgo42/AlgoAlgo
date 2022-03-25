import sys
channel = int(sys.stdin.readline().rstrip())
cnt = int(sys.stdin.readline().rstrip())
broken = []
if cnt != 0:
	broken = list(map(int, sys.stdin.readline().split()))
buttons = []
for i in range(10):
	if i not in broken:
		buttons.append(i)
answer = abs(int(channel) - 100)

def dfs(num, l):
	global answer
	if l > 6:
		return
	
	if l != 0:
		answer = min(answer, l + abs(int(channel) - int(num)))
				
	for i in buttons:
		tmp = num*10 + i
		dfs(tmp, l+1)

dfs(0, 0)
print(answer)