def solution(name):
    answer = 0
    temp = list(name)
    
    for c in temp:
        if ord(c) > 78:
            answer += ord('Z') - ord(c) + 1
        else:
            answer += ord(c) - ord('A')
    
    cnt1 = countstraight(name)
    cnt2 = countrev(name)
    cnt3 = countfront(name)

    answer += min(cnt1, cnt2, cnt3)

    return answer

def countfront(name):
    cnt = 0
    tmp = 0

    for i in range(1, len(name)//2):
        if name[i] == 'A':
            tmp += 1
        else:
            if tmp > len(name)//2 - i:
                break
            cnt += 1 + tmp
            tmp = 0
    cnt = cnt * 2

    if tmp > 0:
        tmp = 0
        for j in range(len(name) - 1, i, -1):
            if name[j] == 'A':
                tmp += 1
            else:
                cnt += 1 + tmp
                tmp = 0
        return cnt
    return float('inf')

def countrev(name):
    cnt = 0
    tmp = 0

    for i in range(len(name) - 1, len(name)//2, -1):
        if name[i] == 'A':
            tmp += 1
        else:
            if tmp > i - len(name)//2:
                break
            cnt += 1 + tmp
            tmp = 0
    cnt = cnt * 2

    if tmp > 0:
        tmp = 0
        for j in range(1, i+1):
            if name[j] == 'A':
                tmp += 1
            else:
                cnt += 1 + tmp
                tmp = 0
        return cnt
    return float('inf')


def countstraight(name):
    cnt1 = 0
    cnt2 = 0
    tmp = 0

    for i in range(1, len(name)):
        if name[i] == 'A':
            tmp += 1
        else:
            cnt1 += 1 + tmp
            tmp = 0
    tmp = 0
    for i in range(len(name) - 1, 0, -1):
        if name[i] == 'A':
            tmp += 1
        else:
            cnt2 += 1 + tmp
            tmp = 0
    return min(cnt1, cnt2)