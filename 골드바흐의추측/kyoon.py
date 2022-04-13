import sys
si = sys.stdin.readline


prime = [1 for _ in range(1000000)]
prime[0] = [0]
prime[1] = [0]
answer = []
for i in range(2, 1000000):
    if prime[i] == 1:
        for j in range(2, 1000000//i + 1):
            if i * j >= 1000000:
                break
            prime[i*j] = 0
        

while True:
    num = int(si().rstrip())
    if num == 0:
        break
    for i in range(2, num//2 + 1):
        flag = False
        if prime[i] == 1 and prime[num - i] == 1:
            answer.append((num, i))
            flag = True
            break
    if flag == False:
        answer.append("Goldbach's conjecture is wrong.")

for i in answer:
    if i == "Goldbach's conjecture is wrong.":
        print(i)
    else:
        print(i[0], "=", i[1], "+", i[0]-i[1])