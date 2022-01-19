# \* 최종코드

```cpp
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
---------------------------------------------
./a.out
1 1 1 2 2 3 3
1 2 1 2 2 3 3
1 2 3 2 2 3 3
k = 3
```

for문 안에 있는 if문으로 다른값[(1 2) or (2 3)]을 찾았을 때 k 변수를 이용하여 서로 다른 숫자를 순서대로 바꾸게 구현

# \* 시행착오

```c
int removeDuplicates(int* nums, int numsSize){
    int len = numsSize;
    int check = 0;

    for (int i = 0; i < len; i++)
    {
        for (int k = i + 1; k < numsSize; k++)
        {
            if (nums[i] != nums[k] || k + 1 == len)
            {
                if (k + 1 == len && nums[i] == nums[k])
                {
                    k = k + 1;
                }
                if (i + 1 == k)
                {
                    break;
                }
                else if (i + 1 != k)
                {
                    int z = k;
                    for (int j = i + 1; z < numsSize; j++)
                    {
                        nums[j] = nums[z];
                        nums[z] = 0;
                        z++;
                    }
                    check = (k - i - 1);
                    len -= check;
                    break;
                }
            }
        }
    }
    return (len);
}
---------------------------------------------
./a.out
1 1 1 2 2 3 3
1 2 2 3 3 0 0
1 2 3 3 0 0 0
1 2 3 0 0 0 0
k = 3
```

초반에 c로 구현 했을 때 결과가 위와 같이 나오게 구현했는데 통과는 했지만 시간이 너무 오래 걸려서 최종코드와 같이 재구현 했습니다.
