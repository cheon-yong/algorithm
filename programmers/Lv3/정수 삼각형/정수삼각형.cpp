#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> res(triangle.size(),vector <int>(triangle.size(),0));
    res[0][0] = triangle[0][0];
    for (int i = 0; i < res.size() - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int left = res[i][j] + triangle[i+1][j];
            int right = res[i][j] + triangle[i+1][j+1];
            
            if (res[i+1][j] < left)
                res[i+1][j] = left;
            
            if (res[i+1][j+1] < right)
                res[i+1][j+1] = right;
        }
    }
    
    for (int i = 0; i < res[res.size() -1].size(); i++)
    {
        if (answer < res[res.size() -1][i])
            answer = res[res.size() -1][i];
    }
    return answer;
}