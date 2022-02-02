#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> mini_split(string s)
{
	vector<string> re;
	string tmp;
	
	for(int i = 0 ; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		tmp = "";
		while (i < s.size() && s[i] != ' ')
		{
			tmp += s[i];
			i++;
		}
		re.push_back(tmp);
	}
	return re;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userMap;

    if (record.size() == 0 || record[0] == "")
        return (record);
    for (int i = 0; i < record.size();i++)
    {
        vector<string> splited = mini_split(record[i]);
        if (splited[0] == "Enter")
        {
            auto finded = userMap.find(splited[1]);
            if (finded != userMap.end())
                userMap[splited[1]] = splited[2];
            else
                userMap.insert({splited[1],splited[2]});
		}
		else if (splited[0] == "Change")
            userMap[splited[1]] = splited[2];
    }

    for (int i = 0; i < record.size();i++)
    {
        vector<string> splited = mini_split(record[i]);
        if (splited[0] == "Enter")
            answer.push_back(userMap[splited[1]] + "님이 들어왔습니다.");
		else if (splited[0] == "Leave")
			answer.push_back(userMap[splited[1]] + "님이 나갔습니다.");
    }
    return answer;
}
