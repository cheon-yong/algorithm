#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int maps[110][110] = { 0 };
int visited[110][110] = { 0 };

int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};

int bfs(int characterX, int characterY, int itemX, int itemY)
{
    queue<pair<pair<int, int>, int>> q;
    
    q.push(make_pair(make_pair(characterX, characterY), 0));
    
    while(q.empty() == false)
    {
        pair<int, int> point = q.front().first;
        int nowX = point.first;
        int nowY = point.second;
        int moveCount = q.front().second;
        
        q.pop();
        if (nowX == itemX && nowY == itemY)
        {
            return moveCount / 2;
        }
        
        moveCount++;
        visited[nowY][nowX] = moveCount;
        for (int i = 0; i < 4; i++)
        {
            int newX = nowX + dirX[i];
            int newY = nowY + dirY[i];
            if (newX < 0 || newY < 0 || newX >= 101 || newY >= 101 ||
               maps[newY][newX] == 0 || maps[newY][newX] == 2 || 
                visited[newY][newX] != 0)
                continue;
            
            q.push(make_pair(make_pair(newX, newY), moveCount));
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    
    // 1. 캐릭터 좌표, 아이템 좌표 모두 2배로 늘린다.
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    // board: 직사각형을 표현할 배열이다.(문제에 직사각형을 나타내는 모든 좌표값은 50이하라고 했지만, 
    // 우리는 모든 좌표값에 대해 2배를 할 것이므로 50*2=100이므로 좌표값은 최대 100이 될 것이다.)
    
    // 직사각형의 시작점과 끝점
    int x1, y1, x2, y2;
    // 2. 직사각형을 board 배열에 모두 입력해준다.
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] = rectangle[i][j] * 2;

        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                maps[y][x] = 1;
    }

    // 3. 직사각형의 내부는 모두 0으로 채워준다.
    for (int i = 0; i < rectangle.size(); i++)
    {
        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1 + 1; y < y2; y++)
            for (int x = x1 + 1; x < x2; x++)
                maps[y][x] = 0;
    }
    
    
    answer = bfs(characterX, characterY, itemX, itemY);
    
    return answer;
}