#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for (string i : participant)
    {
        auto it = m.find(i);
        if (it != m.end()) 
            it->second++;
        m.insert({i, 1});
    }
    for (string k : completion)
    {    
        auto it = m.find(k);
        if (it->second > 1) 
            it->second--;   
        else
            m.erase(k);
    }    
    answer = m.begin()->first;

    return answer;
}
