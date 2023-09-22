#include <string>
#include <vector>
#include <queue>
    
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q(works.begin(), works.end());
    
    for (int i = 0; i < n; i++)
    {
        if (q.top() > 0)
        {
            int temp = q.top();
            q.pop();
            q.push(temp - 1);
        }
    }
    
    while (!q.empty())
    {
        int temp = q.top();
        q.pop();
        answer += temp * temp;
    }
    
    return answer;
}