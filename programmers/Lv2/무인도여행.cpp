#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool visited[101][101] = {false};
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};
int maxX = 0;
int maxY = 0;
vector<string> map;

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int score = 0;
    
    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        score += map[nowX][nowY] - '0';
        for (int i = 0; i < 4; i++)
        {
            int newX = nowX + dirX[i];
            int newY = nowY + dirY[i];
            if (newX >= maxX || newY >= maxY || newX < 0 || newY < 0
               || visited[newX][newY] == true || map[newX][newY] == 'X')
            {
                continue;
            }
                
            
            q.push({newX, newY});
            visited[newX][newY] = true;
        }
    }
    
    return score;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    map = maps;
    maxX = maps.size();
    maxY = maps[0].size();
    for (int x = 0; x < maps.size(); x++)
    {
        for (int y = 0; y < maps[x].size(); y++)
        {
            if (visited[x][y] == false && maps[x][y] != 'X')
            {
                answer.push_back(bfs(x,y));
            }
        }
    }
    
    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end(), less<int>());
    
    return answer;
}