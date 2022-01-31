/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let k = 0;
    nums.forEach(ele => {
        if (ele !== val)
            nums[k++] = ele;
    })
    return k;
};