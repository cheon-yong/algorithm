#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> lists;
    unordered_map<string, int> items;
    
    int answer = 0;
    
    for (int i = 0; i < want.size(); i++)
        lists.insert({want[i], number[i]});
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        int arrange = i + 10;
        bool correct = true;
        for (int j = i; j < arrange; j++)
        {
            string item = discount[j];
            if (lists.find(item) == lists.end())
            {
                correct = false;
                break;
            }
            
            items[item] += 1;
        }
        
        for (auto it = lists.begin() ; it != lists.end() ; it++)
        {
            if (items[it->first] != it->second)
            {
                correct = false;
                break;
            }
        }
        
        if (correct)
        {
            answer++;
        }
            
        items.clear();
    }
    return answer;
}