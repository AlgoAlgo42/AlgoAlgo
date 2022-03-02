#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void combination(string order, map<string, int> &com, int len, string win, int next)
{
	if (next > order.size())
		return ;
	if ( win.size() == len)
	{
		map<string,int>::iterator iter = com.find(win);
		if (iter == com.end())
			com.insert({win,1});
		else
			com[win]++;
		return ;
	}
	combination(order, com, len, win+order[next], next+1);
	combination(order, com, len, win, next+1);
	return;
}

bool comp(pair<string,int> i, pair<string, int>j)
{
	return i.second<j.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int j = 0 ; j  < course.size();j ++)
    {
	    map<string, int> com;
        for (int i = 0 ; i < orders.size(); i++)
        {
            sort(orders[i].begin(),orders[i].end());
            combination(orders[i], com, course[j], "", 0);
        }
        map<string, int>::iterator iter;
        map<string, int>::iterator max = max_element(com.begin(),com.end(),comp);
        for (iter = com.begin();iter != com.end();iter++)
            if (iter->second == max->second && iter->second >1)
                answer.push_back(iter->first);
    }
    sort(answer.begin(),answer.end());
    return answer;
}

