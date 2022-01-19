#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>::iterator first = nums.begin();
        std::vector<int>::iterator last = nums.end();
        std::vector<int>::iterator cursor;
        
        if (nums.size() == 0) return 0;
        cursor = first;
        while (++first != last)
        {
            if (*cursor != *first)
            {
                ++cursor;
                if (*cursor != *first)
                {
                    *cursor = *first;
                }
            }
        }
        return std::distance(nums.begin(), cursor) + 1;
    }
};