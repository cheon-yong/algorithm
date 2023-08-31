#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCount = 0;
    int changeCount = 0;
    
    while (s != "1")
    {
        changeCount++;
        // delete zero
        string newS = "";
        int newSSize = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zeroCount++;
            else
                newSSize++;
        }
        
        // create new s
        s = "";
        while(newSSize > 0)
        {
            s += to_string(newSSize % 2);
            newSSize /= 2;
        }
    }
    
    answer.push_back(changeCount);
    answer.push_back(zeroCount);
    return answer;
}