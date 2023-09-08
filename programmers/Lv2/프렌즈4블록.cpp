#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool existBlock = true;
    
    vector<vector<int>> blocks;
    for (int i = 0; i < board.size(); i++)
    {
        vector<int> v(board[0].size(), 0);
        blocks.push_back(v);
    }
    
    while (existBlock)
    {
        // 초기화
        existBlock = false;
        for (int i = 0; i < blocks.size(); i++)
        {
            for (int j = 0; j < blocks[i].size(); j++)
            {
               blocks[i][j] = 0;
            }
        }
        
        // 보드 체크
        for (int i = 0; i < board.size() - 1; i++)
        {
            for (int j = 0; j < board[i].size() - 1; j++)
            {
                char character = board[i][j];
                if (character == '0')
                    continue;
                
                if (board[i + 1][j] == character && 
                    board[i][j + 1] == character &&
                   board[i + 1][j + 1] == character)
                {
                    blocks[i][j] = 1;
                    blocks[i + 1][j] = 1;
                    blocks[i][j + 1] = 1;
                    blocks[i + 1][j + 1] = 1;
                    existBlock = true;
                }
            }
        }
        
        if (existBlock == false)
            break;
        
        // 제거
        for (int i = 0; i < blocks.size(); i++)
        {
            for (int j = 0; j < blocks[i].size(); j++)
            {
                if (blocks[i][j] == 1)
                {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }
        
        // 아래로 내리기
        for (int i = 0; i < n; i++)
        {
            int position = m - 1;
            while (position >= 0)
            {
                if (board[position][i] == '0')
                {
                    int temp = position - 1;
                    while (temp >= 0)
                    {
                        if (board[temp][i] != '0')
                        {
                            board[position][i] = board[temp][i];
                            board[temp][i] = '0';
                            break;
                        }
                        temp--;
                    }
                }
                
                position--;
            }
        }
    }
    return answer;
}