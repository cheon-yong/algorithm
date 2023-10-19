#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int dp[1001][3] = {0,};    
    int color[1001][3] = {0,};
	int N;
	cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][1], dp[i-1][0]);
    }

    int result = min(dp[N][0], min(dp[N][1], dp[N][2]));
    cout << result << endl;
	return 0;
}