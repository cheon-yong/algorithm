#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    vector<long long> T;
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        T.push_back(temp);
    }

    sort(T.begin(), T.end());
    long long start = 1;
    long long end = T[N - 1] * M;
    long long result = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long count = 0;
        for (int i = 0; i < N; i++)
        {
            count += (mid / T[i]);
        }

        if (count >= M)
        {
            end = mid - 1;
            result = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}