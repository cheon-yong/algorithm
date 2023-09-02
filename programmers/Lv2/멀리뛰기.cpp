#include <string>
#include <vector>

using namespace std;

long long log[2001] = { 0 };

long long getAnswer(int n)
{
    if (n == 1 || n == 2)
        return n;
    
    if (log[n] != 0)
        return log[n];
    
    long long temp = getAnswer(n - 1) + getAnswer(n - 2);
    log[n] = temp % 1234567;
    return temp;    
}

long long solution(int n) {
    long long answer = getAnswer(n) % 1234567;
    
    return answer;
}