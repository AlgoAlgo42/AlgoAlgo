#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int len = land.size() - 1;
    for (int i = 0; i < len; i++)
    {
        land[i+1][0] += std::max({land[i][1],land[i][2],land[i][3]});
        land[i+1][1] += std::max({land[i][0],land[i][2],land[i][3]});
        land[i+1][2] += std::max({land[i][0],land[i][1],land[i][3]});
        land[i+1][3] += std::max({land[i][0],land[i][1],land[i][2]});
    }
    answer = *max_element(land[len].begin(), land[len].end());
    return answer;
}
