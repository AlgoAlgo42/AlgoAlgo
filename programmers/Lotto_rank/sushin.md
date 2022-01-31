```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {


    vector<int> answer(2,6);
    vector<int> rule = {5, 4, 3, 2, 1};
    int match = 0;
    int zero = count(lottos.begin(), lottos.end(), 0);   // 1

    for (int i = 0; i < 6; i++)        // 2
    {
        auto it = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (it != win_nums.end())
            match += 1;
    }

    if (match >= 2)          // 3
    {
        answer[0] = rule[match + zero - 2];
        answer[1] = rule[match - 2];
    }
    else if (match + zero >= 2)
    {
        answer[0] = rule[match + zero - 2];
    }

    return answer;
}
```

1번 zero 변수에 내번호의 0의 갯수를 세줬습니다.  
2번 for문에서 내번호와 로또번호를 비교해서 맞는 번호를 찾아 숫자를 세줬습니다.  
(match 변수에 저장)  
2번 if else를 통해 match와 zero 조건으로 미리 만들어 둔 순위(rule)를 참조해 return 값에 넣어줬습니다.
