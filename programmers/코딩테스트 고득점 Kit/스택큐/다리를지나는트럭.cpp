#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next = 0;
    int nowWeight = 0;
    
    queue<int> bridge;
    
    while (1)
    {
        if (next == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        
        answer++;
        
        int temp = truck_weights[next];
        
        if (bridge.size() == bridge_length)
        {
            nowWeight -= bridge.front();
            bridge.pop();
        }
        
        if (nowWeight + temp <= weight)
        {
            bridge.push(temp);
            nowWeight += temp;
            next++;
        }
        else
        {
            bridge.push(0);
        }
    }
    return answer;
}