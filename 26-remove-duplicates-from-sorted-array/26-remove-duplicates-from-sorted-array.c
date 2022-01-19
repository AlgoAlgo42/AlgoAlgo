int removeDuplicates(int* nums, int numsSize)
{
    int cur = 0;
    int uni = 0;
    int ret = 0;
    
    while (uni < numsSize)
    {
        nums[cur] = nums[uni];
        ret++;
        while(uni < numsSize && nums[cur] == nums[uni])
            uni++;
        cur++;
    }
    return (ret);
}