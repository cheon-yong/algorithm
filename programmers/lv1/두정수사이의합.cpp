#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long big = 0;
    long long small = 0;
    if (a == b)
        return a;
    
    else
    {
        big = max(a, b);
        small = min(a, b);
    }
    
    
    for (int i = small; i <= big; i++)
        answer += i;
        
    return answer;
}