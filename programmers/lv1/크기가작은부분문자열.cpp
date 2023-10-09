#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long pNum = stoll(p);
    int pLength = p.size();
    
    for (int i = 0; i < t.size() - pLength + 1; i++)
    {
        string str = t.substr(i, pLength);
        
        while (str[0] == '0' && str.size() > 1)
        {
            str = str.substr(1);
        }
        
        if (pNum >= stoll(str))
            answer++;
    }
    return answer;
}