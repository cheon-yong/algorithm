#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int col[15] = {0,};
int N;
int answer = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    }

    return true;
}

void nqueen(int x)
{
    if (N == x)
        answer++;

    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
                nqueen(x + 1);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    nqueen(0);
    cout << answer << endl;    

	return 0;
}