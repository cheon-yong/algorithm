// solution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

bool checkPrime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i != 0)
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = n; i <= m; i++)
    {
        if (checkPrime(i))
            cout << i << endl;
    }
    return 0;
}