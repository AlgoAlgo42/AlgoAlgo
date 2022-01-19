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
int main()
{
	Solution s;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	s.removeDuplicates(v);
	std::cout << "ex3) [*iter] iterator : ";
    std::vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end() ; iter++){
        std::cout << *iter << " ";
    }
    std::cout << std::endl << std::endl;
}
