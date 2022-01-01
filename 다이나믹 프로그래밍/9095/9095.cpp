/*
���� 
���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�. ���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

- ������ -
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