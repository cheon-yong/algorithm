#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[201] = {0};
vector<vector<int>> maps;

void dfs(int node)
{
    int len = maps.size();
    visited[node] = 1;
    for (int i = 0; i < maps.size(); i++)
    {
        int nextNode = maps[node][i];
        if (visited[i] == 1 || nextNode == 0)
            continue;
        
        dfs(i);
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    maps = computers;
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            answer++;
        }
        
    }
    
    return answer;
}