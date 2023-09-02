#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> maps;
    
    for (int i = 0; i < tangerine.size(); i++)
    {
        if (maps.find(tangerine[i]) != maps.end())
        {
            maps[tangerine[i]] += 1;
        }
        else
        {
            maps[tangerine[i]] = 1;
        }
    }
    
    vector<pair<int, int>> v(maps.begin(), maps.end());
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < v.size(); i++)
    {
        answer++;
        k -= v[i].second;
        if (k <= 0)
            break;
    }
    
    return answer;
}