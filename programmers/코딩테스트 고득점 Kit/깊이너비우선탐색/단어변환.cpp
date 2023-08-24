#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int visit[51] = {0};
int counts[51] = {1000000};

bool CanGo(string begin, string target)
{
    int count = 0;
    for (int i = 0; i < begin.size(); i++)
    {
        if (count > 1)
            break;
        
        if (begin[i] != target[i])
            count++;
    }
    
    return count == 1 ? true : false;
}

int bfs(string begin, string target, vector<string> words)
{
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    while(!q.empty())
    {
        string nowStr = q.front().first;
        int count = q.front().second;
        
        if (nowStr == target)
        {
            return count;
        }
        q.pop();
        count++;
        for (int i = 0; i < words.size(); i++)
        {
            if (visit[i] == 1)
                continue;
            
            if (CanGo(nowStr, words[i]) == false)
                continue;
            
            visit[i] = 1;
            counts[i] = count;
            q.push(make_pair(words[i], count));
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool find = false;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
        {
            find = true;
            break;
        }
    }
    if (find == false)
        return answer;
    
    answer = bfs(begin, target, words);
    
    
    return answer;
}