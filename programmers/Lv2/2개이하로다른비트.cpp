#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(long long n)
{
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i] + 1);
        }
        else
        {
            long long bit = 1;
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2; 
            }
            bit = bit / 2;

            answer.push_back(numbers[i] + bit);
        }
    }
    
    return answer;
}