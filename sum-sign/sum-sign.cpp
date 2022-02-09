#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0 ; i < absolutes.size(); i++)
        answer += absolutes[i] * ( (signs[i] * 2) - 1);
    return answer;
}

