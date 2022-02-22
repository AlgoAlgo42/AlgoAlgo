#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    
    for (int i = 0; i < w; i++)
        answer -= (int)ceil(((double)(i + 1) * h  /  w) - floor((double)i * h / w));
    return answer;
}
