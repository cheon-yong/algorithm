#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> log;
    
    log.insert(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        string last = words[i - 1];
        string now = words[i];
        if (log.find(now) != log.end() || last[last.size() - 1] != now[0])
        {
            int order = i % n + 1;
            int turn = (i + n) / n;
            answer.push_back(order);
            answer.push_back(turn);
            break;
        }
        
        log.insert(words[i]);
    }
    
    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    

    return answer;
}