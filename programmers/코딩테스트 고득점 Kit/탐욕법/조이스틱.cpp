#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    vector<int> updownCounts(name.size(), 0);
    vector<int> visited(name.size(), 0);
    int moveCount = n - 1;
    
    for (int x = 0; x < name.size(); x++)
    {
        answer += min(abs(name[x] - 'A'), 26 - abs('A' - name[x]));
        
        int y = x + 1;
        while (y < n && name[y] == 'A')
        {
            y++;
        }
        
        moveCount = min(moveCount, x + n - y + min(x, n - y));
    }
    
    answer += moveCount;
    
    return answer;
}

// 다양한 테스트케이스를 세우자