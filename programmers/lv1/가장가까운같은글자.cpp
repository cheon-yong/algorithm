#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        if (map.find(s[i]) == map.end())
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - map[s[i]]);
            map[s[i]] = i;            
        }
        
        map[s[i]] = i;
    }
    
    return answer;
}