#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;
int dist = 0;
int N = 0;
vector<int> nodes;
int edges[20001][20001] = {0, };

void bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    nodes[startNode] = 1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        dist = nodes[node] + 1;
        for (int i = 1; i <= N; i++)
        {
            if (edges[node][i] == 1 && nodes[i] == 0)
            {
                nodes[i] = dist;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N = n;
    for (int i = 0; i <= n; i++)
        nodes.push_back(0);
    
    for (int i = 0; i < edge.size(); i++)
    {
        edges[edge[i][0]][edge[i][1]] = 1;
        edges[edge[i][1]][edge[i][0]] = 1;
    }
    
    bfs(1);
    
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i] == dist - 1)    
            answer++;
    }
    return answer;
}