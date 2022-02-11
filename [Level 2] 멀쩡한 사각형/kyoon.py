def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def solution(w,h):
    if w == 1 or h == 1:
        return 0
    if w == h:
        return w * h - h
    answer = w * h
    x = 0
    if w > h:
        temp = h
        h = w
        w = temp
    g = gcd(w, h)
    res = 0
    a = w / h
    l = (int)(h/g)
    for i in range(l):
        res += 1
        if x < (int)(a * i) :
            x += 1
            if a * i - x != 0:
                res += 1
    answer -= res * g
    return answer
print(solution(100000000, 999999999))