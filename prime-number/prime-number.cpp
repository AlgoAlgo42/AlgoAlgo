#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int isFrame(int n)
{
    if (n < 4)
        return true;
    for (int j = 2 ; j < ( static_cast<int>(sqrt (n))) + 1; j++ )
            if (n % j == 0)
                return (0);
    return (true);
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int x = 0 ; x + 2 < nums.size(); x++)
        for (int y = x + 1; y + 1 < nums.size();y++)
            for (int z = y + 1; z < nums.size(); z++)
                if (isFrame(nums[x] + nums[y] + nums[z]))
                    answer++;
    return answer;
}

