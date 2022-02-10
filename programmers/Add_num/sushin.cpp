#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    for (int i = 0; i <= 9; i++)
        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
            answer += i;
    
    return answer;
}
