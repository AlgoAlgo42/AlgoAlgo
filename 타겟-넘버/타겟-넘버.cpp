#include <string>
#include <vector>
#include <cmath>
using namespace std;
int makeTarget(int targetCase, vector<int> numbers)
{
    int ret = 0;
    for(int i = 0 ; i < numbers.size(); i++)
    {
        ret += numbers[i] * (((targetCase % 2) * - 2) + 1);
        targetCase /= 2;
    }
    return (ret);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for (int i = 0 ; i < pow(2,numbers.size());i++)
        if (makeTarget(i, numbers) == target)
            answer++;    
    return answer;
}

