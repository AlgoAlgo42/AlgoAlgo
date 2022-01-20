#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		nums.erase(std::unique(nums.begin(),nums.end()),nums.end());
		return nums.size();
	}
};
