#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int dp[1001] = {0,};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int N;
	cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[N] << endl;
	return 0;
}