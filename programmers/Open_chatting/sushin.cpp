#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string uidTemp;
    map<string, string> map;
    int k = 0, l = 0, r = 0;
    
    
    for (int i = record.size() - 1; i >= 0; i--)
    {
        if (record[i].find("Leave") == string::npos)
        {
            l = record[i].find(' ');
            r = record[i].find(' ', l + 1);
            uidTemp = record[i].substr(l + 1, r - l - 1);
            if (map.find(uidTemp) == map.end())
                map.insert({uidTemp, record[i].substr(r + 1)});
        }
    }
    for (string i : record)
    {
        if (i.find("Enter") != string::npos)
        {
            k = i.find(' ', 6);
            auto it = map.find(i.substr(6, k - 6));
            answer.push_back(it->second + "님이 들어왔습니다.");
        }
        else if (i.find("Leave") != string::npos)
        {
            k = i.find(' ', 6);
            auto it = map.find(i.substr(6, k - 6));
            answer.push_back(it->second + "님이 나갔습니다.");
        }
    }
    return answer;
}
