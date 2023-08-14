#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    int len = s.length();
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            st.push(1);
        }
        else
        {
            if (st.empty())
            {
                answer = false;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }
    
    if (st.empty() == false)
        answer =false;

    return answer;
}