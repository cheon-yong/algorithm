#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int wordIndex = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            wordIndex = 0;
            continue;
        }
        
        if (wordIndex % 2 == 0 && s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
        else if (wordIndex % 2 == 1 && s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
                
        wordIndex++;
    }
    return answer = s;
}