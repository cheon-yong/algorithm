#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> numbers;
    
    int i = 0;
    int number = 0;
    for (int i = 0; i < s.size(); i++)
    {   
        if (s[i] == ' ' || i == s.size() - 1)
        {
            string temp = s.substr(number, i);
            numbers.push_back(stoi(temp));
            number = i + 1;
        }
    }
    
    int min = numbers[0];
    int max = numbers[0];
    
    for (int i = 0 ; i < numbers.size(); i++)
    {
        if (min > numbers[i])
            min = numbers[i];
        
        if (max < numbers[i])
            max = numbers[i];
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}