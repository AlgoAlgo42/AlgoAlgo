#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string word_map[10] = {"z","o","tw","th","fo","fi","si","se","e","n"};
    int word_lenght[10] = {4,3,3,5,4,4,3,5,5,4};
    for (int i = 0 ; i < s.size();i++)
    {
        if (isdigit(s[i]))
        {
            answer*=10;
            answer+=(static_cast<int>(s[i]) - 48);
            continue;
        }
        else
        {
            for (int j = 0; j < 10 ;j++)
            {
				printf("%s %s\n",word_map[j].c_str(),s.substr(i,word_map[j].size()).c_str());
                if ( word_map[j] == s.substr(i,word_map[j].size()) )
                    {
                        answer*=10;
                        answer += j;
                        i+=word_lenght[j] - 1;
                        break;
                    }
            }
        }
    }
    return answer;
}
