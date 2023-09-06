#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string numbers = "0123456789ABCDEF";

// n을 k 진법으로
string change(int k, long long n)
{
    if (n == 0)
        return "0";
    string s = "";
    while(n > 0) {
        s += numbers[n % k];
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    long long num = 0;
    string s = "";
    int i = p - 1;
    while (answer.size() != t)
    {
        if (i >= s.size())
        {
            s += change(n, num);
            num++;
            continue;
        }
        
        answer += s[i];
        i += m;
    }
    
    return answer;
}