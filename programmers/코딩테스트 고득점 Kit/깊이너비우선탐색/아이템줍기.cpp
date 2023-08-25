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

    
    // 1. ĳ���� ��ǥ, ������ ��ǥ ��� 2��� �ø���.
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    // board: ���簢���� ǥ���� �迭�̴�.(������ ���簢���� ��Ÿ���� ��� ��ǥ���� 50���϶�� ������, 
    // �츮�� ��� ��ǥ���� ���� 2�踦 �� ���̹Ƿ� 50*2=100�̹Ƿ� ��ǥ���� �ִ� 100�� �� ���̴�.)
    
    // ���簢���� �������� ����
    int x1, y1, x2, y2;
    // 2. ���簢���� board �迭�� ��� �Է����ش�.
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

    // 3. ���簢���� ���δ� ��� 0���� ä���ش�.
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