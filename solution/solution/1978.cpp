// solution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int checkPrime(int num)
{
    if (num == 2)
        return 1;
    if (num <= 1)
        return 0;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    int *nums;
    cin >> n;

    nums = new int[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += checkPrime(nums[i]);
    }
    cout << res << endl;
    return 0;
}