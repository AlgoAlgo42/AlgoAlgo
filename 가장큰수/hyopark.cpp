#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int curr ;

bool rev(int i, int j)
{
    string si = to_string(i);
    string sj = to_string(j);
    return (si + sj > sj + si);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),rev);
    for (int i = 0 ; i < numbers.size();i++)
        answer += to_string(numbers[i]);
    if (answer[0] == '0')
        return ("0");
    return answer;
}

