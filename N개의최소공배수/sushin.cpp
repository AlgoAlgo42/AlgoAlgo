#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int max = *max_element(arr.begin(), arr.end());
    int maxValue = max;
    
    while (1)
    {
        int count = 0;
        for (int i : arr)
        {
            if (max % i != 0)
            {
                max += maxValue;
                break;
            }
            count++;
        }
        if (count == arr.size())
            return max;
    }
}
