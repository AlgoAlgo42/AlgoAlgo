#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  
    
    vector<int> answer(2,6);
    vector<int> rule = {5, 4, 3, 2, 1};
    int match = 0;
    int zero = count(lottos.begin(), lottos.end(), 0);
    
    for (int i = 0; i < 6; i++)
    {    
        auto it = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (it != win_nums.end())
            match += 1;
    }
    
    if (match >= 2)
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
