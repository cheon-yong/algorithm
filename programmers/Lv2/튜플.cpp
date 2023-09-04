#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool comp(const vector<int> &a, const vector<int> &b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> numbers;
    
    int cover = 0;
    int vectorIndex = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
        {
            cover++;
            if (cover == 2)
            {
                vector<int> v;
                numbers.push_back(v);
            }
        }
        
        else if (s[i] == '}')
        {
            cover--;
            if (cover == 1)
            {
                vectorIndex++;
            }
        }
        
        else if (s[i] != ',')
        {
            int j = i;
            while (s[j] != ',' && s[j] != '}')
            {
                j++;
            }
            int number = stoi(s.substr(i, j - i + 1));
            i = j - 1;
            numbers[vectorIndex].push_back(number);
        }
    } 
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (int i = 0 ; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers[i].size(); j++)
        {
            if (find(answer.begin(), answer.end(), numbers[i][j]) == answer.end())   
                answer.push_back(numbers[i][j]);
        }
    }
    
    return answer;
}