#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        vector<int> A, B;
        int N, M;
        cin >> N >> M;
        for (int n = 0; n < N; n++)
        {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        for (int m = 0; m < M; m++)
        {
            int temp;
            cin >> temp;
            B.push_back(temp);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int result = 0;
            for (int j = 0; j < M; j++)
            {
                if (A[i] <= B[j])
                {
                    break;
                }
                result++;
            }

            sum += result;
        }
        cout << sum << endl;
    }
    return 0;
}