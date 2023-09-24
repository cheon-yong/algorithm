#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> keys;
    
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            if (keys.find(keymap[i][j]) == keys.end())
            {
                keys[keymap[i][j]] = j + 1;
                continue;
            }
            
            if (keys[keymap[i][j]] > j + 1)
                keys[keymap[i][j]] = j + 1;
        }
    }
    
    for (int i = 0; i < targets.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            if (keys.find(targets[i][j]) == keys.end())
            {
                sum = -1;
                break;
            }
            
            sum += keys[targets[i][j]];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}

