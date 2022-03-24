import sys
str = sys.stdin.readline().rstrip()
str = str.upper()
str = list(str)
str.sort()
cnt = 0
max = 0
c = str[0]
maxc = ''
for i in range(len(str)):
    if c != str[i]:
        cnt = 1
    else:
        cnt += 1
    if cnt > max:
        maxc = c
        max = cnt
    elif cnt == max:
        maxc = '?'
    c = str[i]

print(maxc)