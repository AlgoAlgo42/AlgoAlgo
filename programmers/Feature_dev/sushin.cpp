#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> temp;
    int k;
    
    for (int i = 0; i < speeds.size(); i++)
        temp.push_back(ceil(double(100 - progresses[i]) / speeds[i]));
    for (int i = 0; i < temp.size(); )
    {
        for (k = i + 1; k < temp.size(); k++)
        {
            if (temp[i] < temp[k])
            {
                answer.push_back(k - i);
                break;
            }
        }
        if (k == temp.size())
        {
            answer.push_back(k - i);
            break;
        }
        i = k;        
    }

    return answer;
}
