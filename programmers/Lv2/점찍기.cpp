#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long getY(int &d, int &x) {
    return sqrt(((long)d*d)-((long)x*x));
}

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i <= d;i += k) 
    {
        answer += floor(getY(d, i) / k) + 1;
    }
    return answer;
}