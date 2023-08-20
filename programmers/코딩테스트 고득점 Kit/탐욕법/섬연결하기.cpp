#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> islands(101);

bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int findParent(int index)
{
    if (islands[index] == index)
        return index;
    
    return islands[index] = findParent(islands[index]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    for (int i = 0; i < n; i++)
    {
        islands[i] = i;
    }
    
    for (int i = 0; i < costs.size(); i++)
    {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];
        
        if (start != end)
        {
            answer += cost;
            islands[end] = start;
        }
    }
    
    return answer;
}