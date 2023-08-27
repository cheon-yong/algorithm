#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    // 홀수는 무조건 하나가 남습니다.
    if(s.empty() || s.size() % 2 != 0)
        return answer;

    stack<char> stk;
    for(int i = 0; i < s.size() ; ++i)
    {
        if(stk.empty() || stk.top() != s[i])
            stk.push(s[i]);
        else
            stk.pop();
        
    }

    if(stk.empty())
        ++answer;
    
    return answer;
}