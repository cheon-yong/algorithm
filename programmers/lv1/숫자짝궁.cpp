#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> x;
    map<char, int> y;
    
    for (int i = 0; i < X.size(); i++)
    {
        x[X[i]]++;
    }
    
    for (int i = 0 ; i < Y.size(); i++)
    {
        y[Y[i]]++;
    }
    
    for (int i = 9; i >= 0; i--)
    {
        int num = min(x[i+'0'], y[i+'0']);
        for(int j = 0; j < num; j++)
        {
            answer += i + '0';
        }
    }
    
    if (answer.size() > 1 && answer[0] == '0')
    {
        answer = "0";
    }
    
    if (answer.size() == 0)
    {
        answer = "-1";
    }
    
    return answer;
}