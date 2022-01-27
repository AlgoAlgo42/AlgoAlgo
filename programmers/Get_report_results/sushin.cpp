#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_size = id_list.size();
    vector<int> answer(id_size, 0);
    vector<string> temp;
    vector<string> id;
    string s;
    
    if (k < 1 || id_size < 1 || report.size() < 1)
        return answer;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (int i = 0; i < report.size(); i++)
    {
        istringstream ss(report[i]);
        while (getline(ss, s, ' '))
        {
            if (!ss.eof())
                id.push_back(s);
            else
                temp.push_back(s);
        }
    }
    
    for (int i = 0; i < id_list.size(); i++)
    {
        if (count(temp.begin(), temp.end(), id_list[i]) >= k)
        {
            auto iter = find(temp.begin(), temp.end(), id_list[i]);
            int idx = iter - temp.begin();
            int anweridx = find(id_list.begin(), id_list.end(), id[idx]) - id_list.begin();
            answer[anweridx] += 1;
            if (iter != temp.end())
            {
                while (iter != temp.end())
                {
                    iter = find(iter + 1, temp.end(), id_list[i]);
                    idx = iter - temp.begin();
                    anweridx = find(id_list.begin(), id_list.end(), id[idx]) - id_list.begin();
                    if (anweridx < id_size) 
                        answer[anweridx] += 1;
                }
            }
        }
    }
    return answer;
}
