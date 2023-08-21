#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	vector<int> A;
	vector<int> answer;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		A.push_back(t);
	}
	
	sort(A.begin(), A.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int number;
		cin >> number;

		int start = 0;
		int end = N - 1;
		int find = 0;
		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (A[mid] == number)
			{
				find = 1;
				break;
			}
			else if (A[mid] > number)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		cout << find << "\n";
	}

	
	return 0;
}