#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int size = s.size();
    int answer = size;
    int temp = 0;
    int n = 0;
    string len;
    
    for (int i = 1, j = 0; i < s.size() + 1; i++)
    {
        temp = size;
        j = 0;
        while(j + i < s.size())
        {
            if ( (s.substr(j, i) == s.substr(j + i, i) ) )
            {
                n = 1;
                while((s.substr(j, i) == s.substr(j + i, i) ))
                {
                    n++;
                    temp -= i;
                    j = j + i;
                }
                len = to_string(n);
                temp += len.size();
            }
            else
                j = j + i;
        }
        if (answer > temp)
            answer = temp;
    }
    return answer;
}
