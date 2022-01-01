/*
문제 
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

- 전용준 -
*/

#include <iostream>

using namespace std;

const int MAX = 11;
int dp[MAX];

int solve(int n)
{
    if (dp[n] != -1)
        return dp[n];
    dp[n] = solve(n-1) + solve(n-2) +solve(n-3);
    return dp[n];
}

int main()
{
    for (int i = 0; i < MAX; i++)
        dp[i] = -1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}