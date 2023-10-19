#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int dp[301] = {0,};
int step[301] = {0,};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int N;
	cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> step[i];
    }

    dp[1] = step[1];
    dp[2] = step[1] + step[2];
    dp[3] = max(step[1] + step[3], step[2] + step[3]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(dp[i - 2] + step[i], dp[i - 3] + step[i-1] + step[i]);
    }

    cout << dp[N] << endl;

	return 0;
}