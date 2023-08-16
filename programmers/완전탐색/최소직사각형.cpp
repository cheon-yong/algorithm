#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    
    int len = sizes.size();
    for (int i = 0; i < len; i++)
    {
        sort(sizes[i].begin(), sizes[i].end());
    }
    
    for (int i = 0; i < len; i++)
    {
        if (sizes[i][0] > w)
            w = sizes[i][0];
        
        if (sizes[i][1] > h)
            h = sizes[i][1];
        
    }
    
    answer = w * h;
    
    return answer;
}