def solution(lottos, win_nums):
    answer = [0,0]
    corr = 0 #맞힌 개수
    zero = 0 #0인 개수
    
    for li in range(len(lottos)):
        if(lottos[li] == 0):
            zero+=1
            continue 
        for wi in range(len(win_nums)):
            if (lottos[li] == win_nums[wi]):
                corr+=1
    if (corr < 2):
        answer[1] = 6
    else:
        answer[1] = 5 - (corr - 2)
    if (corr + zero < 2):
        answer[0] = 6
    else:
        answer[0] = 5 - (corr + zero - 2)

    return answer
#git 어려워
