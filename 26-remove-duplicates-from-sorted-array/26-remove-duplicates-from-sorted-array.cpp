class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int numsSize = nums.size();
        int k = 1;
        if (numsSize == 0)
            return 0;

        for (int i = 1; i < numsSize; i++)
        {
            if (nums[i - 1] != nums[i])
                nums[k++] = nums[i];
        }
        return (k);
    }
};