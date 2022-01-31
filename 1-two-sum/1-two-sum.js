/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let a = nums.length - 1;
    let b = 0;
    while (0 < a && nums[a] + nums[b] !== target)
    {
        b++;
        if (a <= b)
        {
            a--;
            b = 0;
        }
    }
    return [a, b];
};