def find(num):
    digit = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    for i in range(0, 10):
        if num == digit[i]:
            return str(i)
    return ''

def solution(s):
    l = len(s)
    answer = ''
    start = 0
    for i in range(0,l):
        res = ''
        if s[i].isdigit():
            res = s[i]
        elif i - start + 1 >= 3:
            res = find(s[start:i+1])

        if res != '':
            start = i+1
            answer += res

    return int(answer)