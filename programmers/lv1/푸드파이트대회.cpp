#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] % 2 == 1)
            food[i]--;
        
        food[i] /= 2;
    }
    
    
    
    for (int i = 1; i < food.size(); i++)
    {
        for (int j = 0; j < food[i]; j++)
        {
            temp += to_string(i);
        }
    }
    answer = temp;
    reverse(temp.begin(), temp.end());
    answer += "0" + temp;
    return answer;
}