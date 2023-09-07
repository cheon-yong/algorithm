#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int DP[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    
    for (int i = 0; i < 1000001; i++)
        DP[i] = 1000001;
    
    DP[x] = 0;
    for (int i = x; i < y; i++)
    {
        if (DP[i] != 1000001)
        {
            if (i * 3 < 1000001)
                DP[i * 3] = min(DP[i] + 1, DP[i * 3]);
            if (i * 2 < 1000001)
                DP[i * 2] = min(DP[i] + 1, DP[i * 2]);
            if (i + n < 1000001)
                DP[i + n] = min(DP[i] + 1, DP[i + n]);
        }
    }
    
    if (DP[y] == 1000001)
        answer = -1;
    else
        answer = DP[y];
        
    return answer;
}