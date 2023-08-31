#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getBinary(int n)
{
    string s = "";
    while(n > 0)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    
    return s;
}

int getOneCount(string s)
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            ret++;
    }
    
    return ret;
}

int solution(int n) {
    int answer = n;
    
    int oneCount = getOneCount(getBinary(n));
    
    while(true)
    {
        answer++;
        int count = getOneCount(getBinary(answer));
        if (count == oneCount)
            break;
    }
    
    return answer;
}