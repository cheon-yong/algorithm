#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (n > 0)
    {
        int check = n / 2;
        if ((a <= check && b <= check))
        {
            n = check;
            continue;
        }
        
        if ((a > check && b > check))
        {
            a -= check;
            b -= check;
            n = check;
            continue;
        }
        
        while (n != 1)
        {
            n /= 2;
            answer++;
        }
    }

    return answer;
}
