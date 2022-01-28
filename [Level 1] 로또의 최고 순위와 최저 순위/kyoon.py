def solution(lottos, win_nums):
    answer = []
    cnt = 0
    zero = 0

    for num in lottos:
        if num == 0:
            zero += 1
    
    for win in win_nums:
        for num in lottos:
            if (win == num):
                cnt += 1
                break
    rank = [6, 5, 4, 3, 2, 1]
    answer = [rank[cnt+zero] if cnt + zero - 1 <= 0 else rank[cnt+zero-1], rank[cnt] if cnt <= 0 else rank[cnt - 1]]

    return answer
