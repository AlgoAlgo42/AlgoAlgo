​# \* 최종코드

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<int> index;          //몇번째 인덱스가 0인지 담아두는 vector

    1.  for (int i = 0; i < matrix.size(); i++)
        {
            auto it = find(matrix[i].begin(), matrix[i].end(), 0); // find함수를 이용 row에서 0 찾기
            if (it != matrix[i].end())
            {
                while (it != matrix[i].end())  // row에 0이 여러개인 것을 잡기위한 반복문
                {
                    index.push_back(it - matrix[i].begin());
                    it = find(it + 1, matrix[i].end(), 0);
                }
                matrix[i].assign(matrix[i].size(), 0); // 0이 있는 row는 assign을 이용해 모두 0으로 할당
            }
        }
    2.  for (int k = 0; k < index.size(); k++)   //vector에 담아놓은 index를 이용하여 col을 0으로 할당해주는 반복문
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][index[k]] != 0)
                {
                    matrix[i][index[k]] = 0;
                }
            }
        }
    }
};
---------------------------------------------
./a.out
0 2 3
3 4 5         Input
1 3 1
----------
0 0 0
3 4 5         1번 for문
1 3 1
----------
0 0 0
0 4 5         2번 for문
1 3 1
----------
0 0 0
0 4 5         2번 for문
0 3 1
---------------------------------------------
./a.out
0 1 4 0
3 4 5 2      Input
1 3 1 5
----------
0 0 0 0
3 4 5 2      1번 for문
1 3 1 5
----------
0 0 0 0
0 4 5 2      2번 for문
1 3 1 5
----------
0 0 0 0
0 4 5 2      2번 for문
0 3 1 5
----------
0 0 0 0
0 4 5 0      2번 for문
0 3 1 5
----------
0 0 0 0
0 4 5 0      2번 for문
0 3 1 0
----------
```
