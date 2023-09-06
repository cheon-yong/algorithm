#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    int index = 1;
    for (char c = 'A'; c <= 'Z'; c++)
	{
		string s = ""; 
        s += c;
		dict[s] = index++;
	}
    
    for (int i = 0; i < msg.size(); i++)
    {
        for (int range = 1; range + i <= msg.size(); range++)
        {
            string word = msg.substr(i, range);
            if (dict.find(word) == dict.end())
            {
                dict[word] = index;
                index++;
                answer.push_back(dict[msg.substr(i, range - 1)]);
                i += range - 2;
                break;
            }
            if (range + i >= msg.size())
            {
                answer.push_back(dict[word]);
                i += range;
                break;
            }
            
        }
    }

    return answer;
}