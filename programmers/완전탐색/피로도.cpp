#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int answer = 0;

void search(int k, int count, int index, vector<vector<int>> dungeons, vector<int> visited)
{
    visited[index] = 1;
    k -= dungeons[index][1];
    answer = max(answer, count);
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i] == 1 || k < dungeons[i][0])
            continue;
        
        search(k, count + 1, i, dungeons, visited);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> visited(dungeons.size(), 0);
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        search(k, 1, i, dungeons, visited);
    }
    
    return answer;
}