#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<int> iq;
    queue<int> jq;

    int i = 0;
    int j = 0;
    int re = 0;
    
    iq.push(0);
    jq.push(0);
    
    while (iq.size())
    {
        re++;
        int len = iq.size();
        for (int x = 0 ; x < len ; x++)
        {
            i = iq.front();
            j = jq.front();
            iq.pop();
            jq.pop();
            if (i == maps.size() - 1 && j == maps[i].size() - 1)
                return (re);
            if (maps[0].size() > j+1 && maps[i][j+1] == 1)
            {
                iq.push(i);
                jq.push(j+1);
                maps[i][j+1]  = -1;
            }
            if (maps.size() > i+1 && maps[i+1][j] == 1)
            {
                iq.push(i+1);
                jq.push(j);
                maps[i+1][j]  = -1;
            }
            if (j-1 >= 0 && maps[i][j-1] == 1)
            {
                iq.push(i);
                jq.push(j-1);
                maps[i][j-1]  = -1;
            }
            if (i-1 >= 0 && maps[i-1][j] == 1)
            {
                iq.push(i-1);
                jq.push(j);
                maps[i-1][j]  = -1;
            }
        }
    }
    return -1;
}

