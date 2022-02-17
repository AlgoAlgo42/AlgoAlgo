#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string base = "124";
    string answer = "";
    
    while (n)
    {
        if (n%3 == 0)
            answer += base[(--n % 3)];
        else
            answer += base[(n % 3) - 1];
        n = n / 3;
    }
    reverse(answer.begin(),answer.end());
    return (answer);
}

