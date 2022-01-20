class Solution:
    def removeDuplicates(self, nums):
        setnums = sorted(list(set(nums)))
        for i in range(0, len(setnums)):
            nums[i] = setnums[i]
        return len(setnums)