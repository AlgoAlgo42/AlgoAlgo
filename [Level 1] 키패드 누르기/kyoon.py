def solution(numbers, hand):
    answer = ''
    position = ['*', '#']
    L = [1,4,7]
    R = [3,6,9]

    for num in numbers:
        res = ''
        if num in L:
            res = 'L'
        elif num in R:
            res = 'R'
        else:
            res = calHand(hand, position, num)
        answer += res
        if res == 'L':
            position[0] = num
        else:
            position[1] = num
    return answer

def calHand(hand, position, num):
    nfloor = calFloor(num)
    ncol = calCol(num)

    lres = abs(nfloor - calFloor(position[0])) + abs(ncol - calCol(position[0]))
    rres = abs(nfloor - calFloor(position[1])) + abs(ncol - calCol(position[1]))

    if lres > rres:
        return 'R'
    elif lres < rres:
        return 'L'
    else:
        if hand == 'right':
            return 'R'
        else:
            return 'L'


def calCol(num):
    col = [[1,4,7,'*'], [2,5,8,0], [3,6,9,'#']]

    if num in col[0]:
        return 1
    if num in col[1]:
        return 2
    if num in col[2]:
        return 3

def calFloor(num):
    if num == '*' or num == '#' or num == 0:
        return 4

    return (int)((num - 1) / 3 + 1)