#include <string>
#include <vector>

using namespace std;

long long arr[60001] = {0};

long long getFibbo(long long n)
{
    if (arr[n] == 0)
    {
        arr[n] = (getFibbo(n - 1) + getFibbo(n - 2)) % 1000000007;
    }
    
    return arr[n];
}

int solution(int n) {
    int answer = 0;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    answer = getFibbo(n);
    
    return answer;
}
