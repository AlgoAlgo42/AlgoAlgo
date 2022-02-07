def pang(sol, num):
    l = len(sol)
    if l > 0 :
        if sol[l - 1] == num:
            sol.pop()
            return 2
    sol.append(num)
    return 0

def find(board, num):
    l = len(board)
    for i in range(l):
        res = board[i][num - 1]
        if res != 0:
            board[i][num - 1] = 0
            break
    return res        
    
def solution(board, moves):
    sol = []
    answer = 0
    for num in moves:
        res = find(board, num)
        if res != 0:
            answer += pang(sol, res)
    return answer