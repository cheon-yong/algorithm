#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, int> numbers;
    
    numbers["zero"] = 0;
    numbers["one"] = 1;
    numbers["two"] = 2;
    numbers["three"] = 3;
    numbers["four"] = 4;
    numbers["five"] = 5;
    numbers["six"] = 6;
    numbers["seven"] = 7;
    numbers["eight"] = 8;
    numbers["nine"] = 9;
    
    int i = 0;
    string temp = "";
    while (i < s.size())
    {
        if (numbers.find(temp) != numbers.end())
        {
            answer *= 10;
            answer += numbers[temp];
            temp = "";
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            answer *= 10;
            answer += s[i] - '0';
        }
        else
        {
            temp += s[i];
        }
        i++;
    }
    if (temp != "")
    {
        answer *= 10;
        answer += numbers[temp];
    }
    return answer;
}