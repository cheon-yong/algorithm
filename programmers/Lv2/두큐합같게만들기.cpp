#include <string>
#include <vector>
#include <queue>
#include <numeric>

#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1 {{begin(queue1), end(queue1)}};
    queue<int> q2 {{begin(queue2), end(queue2)}};
    // sum
    long long sum1 = accumulate(begin(queue1), end(queue1), 0ll);
    long long sum2 = accumulate(begin(queue2), end(queue2), 0ll);

    if ((sum1 + sum2) % 2 == 1)
        return -1;
    
    int s1 = queue1.size();
    int s2 = queue2.size();
    
    while(true)
    {
        if(answer > s1 + s2 + 2) 
            return -1;
        
        if (sum1 == sum2)
            break;
        
        answer++;
        if(sum1 < sum2) {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        else {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
    }
    
    
    return answer;
}