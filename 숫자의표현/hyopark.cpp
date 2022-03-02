#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int solution(int n) {
    int sol = 0;
    int start = 0;
    int set = 0;
    int iter = n;
    
    while (iter)
    {
        if (set == 0)
            start = iter;
        set += iter;
        if(set >= n)
        {
            if (set == n)
                sol++;
            iter = start-1;
            set = 0;
            continue ;
        }
        iter--;
    }
    return (sol);
}

