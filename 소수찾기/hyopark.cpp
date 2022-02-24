#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int isFrame(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return (true);
    for (int j = 2 ; j < ( static_cast<int>(sqrt (n))) + 1; j++ )
            if (n % j == 0)
                return (0);
    return (true);
}

int re(int n, int first, string numbers, vector<int> domain, string now, vector<int> &visited)
{
    int ret = 0;
    if (n == 1)
    {
        for (int idx = 0 ; idx < domain.size(); idx++)
        {
            int value = stoi(now+to_string(domain[idx]));
            if (isFrame(value) && visited.end() == find(visited.begin(),visited.end(),value))
            {
                visited.push_back(value);
                ret++;
            }
        }
        return ret;
    }
    for (int idx = 0; idx < domain.size(); idx++)
    {
        vector<int> tmp = domain;
        tmp.erase(find(tmp.begin(),tmp.end(), domain[idx]));
        ret += re(n-1, idx, numbers, tmp, now + to_string(domain[idx]), visited);
    }
    return ret;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    vector<int> visited;
    for(int i = 0 ; i < numbers.length();i++)
        v.push_back(static_cast<int>(numbers[i] - 48));
    for(int i = 1 ; i <= numbers.length();i++)
        answer += re(i,0,numbers,v,"" , visited );
    return answer;
}

