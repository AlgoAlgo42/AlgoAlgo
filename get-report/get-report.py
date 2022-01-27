def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report = set(report)
    tmp = []
    tmp2 = []
    
    for r in report:
        tmp.append(r.split(' ')[1])
        tmp2.append(r.split(' ')[0])
    for tdx, t in enumerate(tmp):
        if (tmp.count(t) >=k):
            answer[id_list.index(str(tmp2[tdx]))]+=1
    return answer
