#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    
    int minPoint = routes[0][0];
    int maxPoint = routes[0][1];
    int len = routes.size();
    answer++;
    for (int i = 1; i < len; i++)
    {
        if (maxPoint < routes[i][0])
        {
            minPoint = routes[i][0];
            maxPoint = routes[i][1];
            answer++;
        }
        else
        {
            minPoint = max(routes[i][0], minPoint);
            maxPoint = min(routes[i][1], maxPoint);
        }
    }
    
    return answer;
}

// -20 -15
// -18 -13
    