def solution(progresses, speeds):
    answer = []
    l = len(speeds)
    while True:
        cnt = 0
        for i in range(l):
            if progresses[i] != -1:
                progresses[i] += speeds[i]
            if (i == 0 or progresses[i-1] == -1) and progresses[i] >= 100:
                cnt += 1
                progresses[i] = -1
        if cnt > 0:
            answer.append(cnt)
        if progresses[l-1] == -1:
            break
    return answer