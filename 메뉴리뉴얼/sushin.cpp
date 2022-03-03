#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<int>> temp;

void combination(int N, int k, string order, int idx)
{
    string num; 
    vector<int> perm(N);

    for (int i = N - k; i < N; i++)
        perm[i] = 1;
    do 
    {
        for(int i = 0; i < perm.size(); i++)
            if (perm[i] == 1)
                num += order[i];
        sort(num.begin(), num.end());
        if (temp.find(num) != temp.end()) 
            temp.find(num)->second.push_back(idx); 
        else 
        {   
            vector<int> j;
            j.push_back(idx);
            temp.insert({num, j});
        }
        num.clear();
    } while(next_permutation(perm.begin(), perm.end()));

}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    vector<int> filter(11, 0);

    for (int k = 0; k < orders.size(); k++)
    {
        for (int i = 0; i < course.size(); i++)
        {    
            if (orders[k].size() < course[i])
                continue;
            combination(orders[k].size(), course[i], orders[k], k + 1);
        }
    }
    for (const auto &item : temp) 
        if (filter[item.first.size()] < item.second.size() && item.second.size() > 1)
            filter[item.first.size()] = item.second.size();
    for (const auto &item : temp)
        if (filter[item.first.size()] == item.second.size())
            answer.push_back(item.first);
    sort(answer.begin(), answer.end());   

    return answer;
}
