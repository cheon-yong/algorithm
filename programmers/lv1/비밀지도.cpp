#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toBin(int n)
{
    string s = "";
    while(n > 0)
    {
        int m = n % 2;
        s = to_string(m) + s;
        n /= 2;
    }
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;
    for (int i = 0; i < arr1.size(); i++)
    {
        string temp = toBin(arr1[i]);
        while (temp.size() < n)
        {
            temp = "0" + temp;
        }
        map1.push_back(temp);
    }
    
    for (int i = 0; i < arr2.size(); i++)
    {
        string temp = toBin(arr2[i]);
        while (temp.size() < n)
        {
            temp = "0" + temp;
        }
        map2.push_back(temp);
    }
    
    for (int i = 0; i < arr1.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (map1[i][j] == '1' || map2[i][j] == '1')
                temp += '#';
            else
                temp += ' ';
        }
        answer.push_back(temp);
    }
    
    return answer;
}