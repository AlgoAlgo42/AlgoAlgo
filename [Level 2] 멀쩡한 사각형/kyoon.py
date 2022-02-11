def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def solution(w,h):
    return w * h - (w + h - gcd(w, h))