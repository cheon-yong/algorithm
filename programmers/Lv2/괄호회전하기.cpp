#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stack<char> stk;
    
    if (s.size() % 2 == 1)
        return 0;
    
    for (int j = 0; j < s.size(); j++)
    {
        while (!stk.empty())
            stk.pop();
        
        int i = (j % s.size()) - 1;
        bool correct = true;
        for (int c = 0; c < s.size(); c++)
        {
            i = (i + 1) % s.size();
            
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            
            else
            {
                if (s[i] == ')' && stk.top() == '(')
                    stk.pop();
                else if (s[i] == '}' && stk.top() == '{')
                    stk.pop();
                else if (s[i] == ']' && stk.top() == '[')
                    stk.pop();
                
                else
                {
                    correct = false;
                    break;
                }
            }
        }
        
        if (correct == true && stk.empty())
            answer++;
    }
        
    
    return answer;
}