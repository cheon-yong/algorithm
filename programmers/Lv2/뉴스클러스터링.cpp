#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

string to_lower(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}

unordered_map<string, int> make_map(string s)
{
    unordered_map<string, int> s_map;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] < 'a' || s[i] > 'z' || s[i+1] < 'a' || s[i+1] > 'z')
            continue;
        
        string temp = s.substr(i, 2);
        if (s_map.find(temp) == s_map.end())
            s_map[temp] = 1;
        else 
            s_map[temp] += 1;
    }
    
    return s_map;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    str1 = to_lower(str1);
    str2 = to_lower(str2);
    
    unordered_map<string, int> s_map1;
    unordered_map<string, int> s_map2;
    
    s_map1 = make_map(str1);
    s_map2 = make_map(str2);
    
    // union
    int gyo = 0;
    for (auto it = s_map1.begin(); it != s_map1.end(); it++)
    {
        string word = it->first;
        if (s_map2.find(word) != s_map2.end())
        {
            gyo += min(it->second, s_map2[word]);
        }
    }
    
    int hap = 0;
    for (auto it = s_map1.begin(); it != s_map1.end(); it++)
    {
        string word = it->first;
        if (s_map2.find(word) != s_map2.end())
        {
            hap += max(it->second, s_map2[word]);
        }
        else
        {
            hap += it->second;
        }
    }
    
    for (auto it = s_map2.begin(); it != s_map2.end(); it++)
    {
        string word = it->first;
        if (s_map1.find(word) == s_map2.end())
        {
            hap += it->second;
        }
    }
    if (gyo == 0 && hap == 0)
        return 65536;
    
    answer = gyo * 65536 / hap;
     
    return answer;
}