import sys
from collections import deque
si = sys.stdin.readline

T = int(si().rstrip())
for _ in range(T):
    p = si().rstrip()
    n = int(si().rstrip())
    seq = deque(si().rstrip()[1:-1].split(","))
    isrev = False
    answer = ""
    for c in p:
        if c == "R":
            isrev = False if isrev else True
        else:
            if n != 0 and seq:
                if isrev:
                    seq.pop()
                else:
                    seq.popleft()
            else:
                answer = "error"
    
    if answer == "error":
        print(answer)
    else:
        print("[", end="")
        if isrev:
            seq.reverse()
        print(",".join(seq), end="")
        print("]")