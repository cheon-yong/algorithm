#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int deleteCount = 0;
    while (deleteCount < k)
    {
        int i = 0;
        for (i = 0; i < number.length(); i++)
        {
            if (number[i] < number[i + 1] || i == number.length() - 1)
            {
                number.erase(i, 1);
                deleteCount++;
                break;
            }
        }
            
    }
    answer = number;
    
    return answer;
}