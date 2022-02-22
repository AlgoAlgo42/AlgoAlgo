#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0, sum = 0, div = 0;
    
    for (int i = 0; i < nums.size(); i++)
        for (int k = i + 1; k < nums.size(); k++)
            for (int p = k + 1; p < nums.size(); p++)
            {
                sum = nums[i] + nums[k] + nums[p];
                for (div = 2; div < sum; div++)
                    if (sum % div == 0)
                        break;
                if (div == sum)
                    answer++;
            }
    return answer;
}
