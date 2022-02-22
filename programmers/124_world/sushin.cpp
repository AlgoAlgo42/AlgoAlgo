#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<char> world = {'4', '1', '2'};
    
    while (n > 0)
    {
        answer = world[n % 3] + answer;
        if (n % 3 == 0)
            n -= 1;
        n /= 3;
    }
    return answer;
}
