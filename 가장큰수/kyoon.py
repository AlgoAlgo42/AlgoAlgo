def is_larger(a, b):
    if int(str(a) + str(b)) > int(str(b) + str(a)):
        return True
    return False

def merge_sort(numbers):
    if len(numbers) < 2:
        return numbers
    
    mid = len(numbers) // 2
    larr = merge_sort(numbers[:mid])
    rarr = merge_sort(numbers[mid:])
    
    res = []
    l = r = 0
    while l < len(larr) and r < len(rarr):
        if is_larger(larr[l], rarr[r]):
            res.append(larr[l])
            l += 1
        else:
            res.append(rarr[r])
            r += 1
    res += larr[l:]
    res += rarr[r:]
    return res

def solution(numbers):
    answer = ''
    if numbers.count(0) == len(numbers):
        return "0"

    numbers = merge_sort(numbers)
    for num in numbers:
            answer += str(num)
    return answer