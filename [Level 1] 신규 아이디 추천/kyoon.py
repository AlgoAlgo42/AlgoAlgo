def is_sign(c):
    sign = ['.', '-', '_']
    for s in sign:
        if s == c:
            return True
    return False

def rm_end_dot(str):
    while len(str) > 0 and str[-1] == '.':
        str.pop()
    return str

def is_dotted(i, str):
    l = len(str)
    if l > i + 1 and str[i + 1] == '.':
        return True
    else:
        return False

def solution(new_id):
    answer = []
    new_id = new_id.lower()
    
    for c in new_id:
        if c.isalpha() or c.isdigit() or is_sign(c) :
            answer += c
    new_id = answer
    answer = []

    for i in range(len(new_id)):
        if new_id[i] == '.' and is_dotted(i, new_id):
            continue
        else:
            answer += new_id[i]
    new_id = answer

    new_id = list(new_id)
    while len(new_id) > 0 and new_id[0] == '.':
        new_id.remove('.')

    new_id = rm_end_dot(new_id)

    if len(new_id) == 0:
        new_id = 'a'
    
    while len(new_id) >= 16:
        new_id.pop()
        new_id = rm_end_dot(new_id)
    
    
    while (len(new_id) > 0 and len(new_id) < 3):
        new_id += (new_id[-1])
    
    answer = "".join(new_id)

    
    return answer
