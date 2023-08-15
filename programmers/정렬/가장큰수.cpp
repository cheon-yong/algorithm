#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int &a, const int &b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    
    // 이 부분이 핵심
    if (sa + sb > sb + sa)
        return true;
    
    return false;
}   

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        answer.append(to_string(numbers[i]));
    }
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}