using namespace std;
#include <iostream>
long long solution(int w,int h) {
    long long s = 0;
    for (double i = 0.0; i  < w ; i+=1.0)
        s += (int)(i * (double)h / (double)w);
    return (2*s);
}
