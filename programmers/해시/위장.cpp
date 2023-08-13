#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++)
        m[clothes[i][1]] += 1;
    
    map<string, int>::iterator iter;

    if (m.size() == 1)
    {
        for (iter = m.begin(); iter != m.end(); iter++)
            answer *= iter->second;
    }
    else
    {
        for (iter = m.begin(); iter != m.end(); iter++)
            answer *= iter->second + 1;
        answer--;
    }
    return answer;
}