#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int dp[1001] = {0,};
int arr[1001] = {0,};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int N;
	cin >> N;


    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int sum=0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sum = max(sum, dp[i]);
    }
    
    cout << sum << endl;

	return 0;
}