#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_set<char> skips;
    
    for (int i = 0; i < skip.size(); i++)
        skips.insert(skip[i]);
    
    for (int i = 0; i < s.size(); i++)
    {
        int num = 0;
        char temp = s[i];
        while (num < index)
        {
            temp += 1;
            if (temp > 'z')
                temp = 'a';
            
            if (skips.find(temp) != skips.end())
                continue;
            
            num++;
        }
        answer += temp;
    }
    
    return answer;
}