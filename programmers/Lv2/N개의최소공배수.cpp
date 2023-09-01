#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    int answer = arr[0];
    while (true)
    {
        bool isAnswer = true;
        for (int i = 0; i < arr.size(); i++)
        {
            if (answer % arr[i] != 0)
            {
                isAnswer = false;
                break;
            }
        }
        
        if (isAnswer)
            break;
        
        answer++;
    }
    
    return answer;
}