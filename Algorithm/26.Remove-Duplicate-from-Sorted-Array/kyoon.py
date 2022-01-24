class Solution(object):
    def removeDuplicates(nums):
        set_nums = set(nums)
        set_nums = list(set_nums)
        set_nums.sort()        
        for i in range(0, len(set_nums)):
            nums[i] = set_nums[i]
        return len(set_nums)