#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void leftTouch(string &answer, vector<int> &fingerP, int row, int col)
{
    answer.push_back('L');
    fingerP = {row, col};
}

void rightTouch(string &answer, vector<int> &fingerP, int row, int col)
{
    answer.push_back('R');
    fingerP = {row, col};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<vector<int>> pad = {{1, 4, 7, 99}, {2, 5, 8, 0}, {3, 6, 9, 99}};
    vector<vector<int>> fingerP = {{3, 0}, {3, 2}};
    int row, l, r;
    
    for (int i : numbers)
    {
        for (int col = 0; col < 3; col++)
        {   
            auto it = find(pad[col].begin(), pad[col].end(), i);
            row = it - pad[col].begin();
                if (row <= 3)
                {    
                    if (col == 0)
                        leftTouch(answer, fingerP[0], row, col);
                    else if (col == 2)
                        rightTouch(answer, fingerP[1], row, col);
                    else
                    {
                        l = abs(fingerP[0][0] - row) + abs(fingerP[0][1] - col);
                        r = abs(fingerP[1][0] - row) + abs(fingerP[1][1] - col);
                        if (l < r)
                            leftTouch(answer, fingerP[0], row, col);
                        else if (l > r)
                            rightTouch(answer, fingerP[1], row, col);
                        else
                        {
                            if (hand == "left")
                                leftTouch(answer, fingerP[0], row, col);
                            else if (hand == "right")
                                rightTouch(answer, fingerP[1], row, col);
                        }
                    }
                }
        }
    }
    return answer;
}
