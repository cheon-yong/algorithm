#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int same = 0;
        int notSame = 0;
        for (j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
                same++;
            else
                notSame++;
            
            if (same == notSame)
            {
                break;
            }
        }
        
        i = j;
        answer++;
    }
    return answer;
}