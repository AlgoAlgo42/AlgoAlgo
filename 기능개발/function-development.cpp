#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 0; i < progresses.size();)
    {
        for (int j = 0; j < progresses.size(); j++)
            progresses[j] += speeds[j];
        if (progresses[i] >= 100)
        {
            int tmp = 0;
            while (i < progresses.size() && progresses[i] >= 100)
            {
                tmp++;
                i++;
            }
            answer.push_back(tmp);
        }
    }
            
    return answer;
}

