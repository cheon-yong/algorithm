#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> list;
    unordered_map<string, int> gemCounts;
    
    int firstIndex = 0;
    int lastIndex = 0;
    int minValue = 0;
    
    // 보석갯수 구하기
    for (int i = 0; i < gems.size(); i++)
    {
        list.insert(gems[i]);
    }
    int gemCount = list.size();
    
    
    // 마지막 인덱스 구하기
    for (int i = 0; i < gems.size(); i++)
    {
        gemCounts[gems[i]]++;
        
        if (gemCounts.size() == gemCount)
        {
            lastIndex = i;
            break;
        }
    }
    minValue = lastIndex - firstIndex;
    answer.push_back(firstIndex + 1);
    answer.push_back(lastIndex + 1);
    
    while (lastIndex < gems.size())
    {
        string key = gems[firstIndex];
        gemCounts[key]--;
        firstIndex++;
        
        if (gemCounts[key] == 0)
        {
            lastIndex++;
            for (; lastIndex < gems.size(); lastIndex++)
            {
                gemCounts[gems[lastIndex]]++;
                if (key == gems[lastIndex])
                    break;
            }
            if (lastIndex == gems.size())
                break;
        }
        
        if (minValue > lastIndex - firstIndex)
        {
            answer[0] = firstIndex + 1;
            answer[1] = lastIndex + 1;
            minValue = lastIndex - firstIndex;
        }
    }
    return answer;
}