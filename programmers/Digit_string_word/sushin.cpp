#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    
    vector<string> word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    auto it = find_if(s.begin(), s.end(), ::isalpha);
    while ( it != s.end() ) 
    {
        temp.push_back(*it);
        if (temp.size() >= 2)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i].substr(0,2) == temp)
                {
                    s.replace(s.find(temp), word[i].size(), to_string(i));
                    temp.clear();
                    it = find_if(s.begin(), s.end(), ::isalpha);
                    break;
                }
            }
        }
        else
            it = find_if(it + 1, s.end(), ::isalpha);
    }
    answer = stoi(s);
    return answer;
}
