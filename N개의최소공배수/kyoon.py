def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

def lcm(a, b):
    return a*b//gcd(a,b)

def solution(arr):
    for i in range(len(arr) - 1):
        arr[i+1] = lcm(arr[i], arr[i+1])
    return arr[-1]