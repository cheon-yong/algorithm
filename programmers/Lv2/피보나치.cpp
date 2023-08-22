#include <string>
#include <vector>

using namespace std;

int fibo[100001] = {0};

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    
    if (fibo[n] == 0)
        fibo[n] = (fibonacci(n-2) + fibonacci(n-1)) % 1234567;
    
    return fibo[n];
}

int solution(int n) {
    int answer = fibonacci(n);
    
    return answer;
}