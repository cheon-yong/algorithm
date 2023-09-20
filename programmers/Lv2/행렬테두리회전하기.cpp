#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int map[101][101] = {0};
    
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {1, 0, -1, 0};
    int count = 1;
    
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            map[i][j] = count++;
        }
    }
    
    for (int i = 0; i < queries.size(); i++)
    {
        int dirIndex = 0;
        
        int nowX = queries[i][0];
        int nowY = queries[i][1];
        
        int nextX = nowX + dirX[dirIndex];
        int nextY = nowY + dirY[dirIndex];
        
        int nowValue = map[nowX][nowY];
        int nextValue = map[nextX][nextY];
        int minValue = count;
        while (dirIndex < 4)
        {
            if (minValue > nowValue)
                minValue = nowValue;
            
            map[nextX][nextY] = nowValue;
            nowValue = nextValue;
            
            switch (dirIndex)
            {
                case 0 :
                {
                    if (nextY + dirY[dirIndex] > queries[i][3])
                        dirIndex++;
                }
                case 1:
                {
                    if (nextX + dirX[dirIndex] > queries[i][2])
                        dirIndex++;
                }
                case 2 :
                {
                    if (nextY + dirY[dirIndex] < queries[i][1])
                        dirIndex++;
                }
                case 3 :
                {
                    if (nextX + dirX[dirIndex] < queries[i][0])
                        dirIndex++;
                }   
            }
            
            if (dirIndex == 4)
                break;
            
            nowX = nextX;
            nowY = nextY;
            
            nextX = nowX + dirX[dirIndex];
            nextY = nowY + dirY[dirIndex];
            nextValue = map[nextX][nextY];
        }
        answer.push_back(minValue);
    }
    
    return answer;
}