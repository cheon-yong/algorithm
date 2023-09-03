#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string to_lower(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s [i] <= 'Z')
            s[i] = s[i] + 32;
    }
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> cache;
    
    for (int i = 0; i < cities.size(); i++)
    {
        string city = to_lower(cities[i]);
        
        // miss
        if (cache.find(city) == cache.end())
        {
            answer += 5;
            
            cache[city] = i;
            if (cache.size() > cacheSize)
            {
                int index = cities.size();
                string candidate = "";
                for (auto it = cache.begin(); it != cache.end(); it++)
                {
                    if (it->second < index)
                    {
                        candidate = it->first;
                        index = it->second;
                    }
                }
                
                cache.erase(candidate);
            }
        }
        // hit
        else
        {
            answer += 1;
            cache[city] = i;
        }   
    }
    
    return answer;
}