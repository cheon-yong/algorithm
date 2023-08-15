#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        auto command = commands[i];
        vector<int> t(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(t.begin(), t.end(), less<int>());
        
        answer.push_back(t[command[2] - 1]);
    }
    
    return answer;
}