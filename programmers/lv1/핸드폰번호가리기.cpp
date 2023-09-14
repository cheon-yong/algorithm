#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int count = 0;
    for (int i = phone_number.size() - 1; i >= 0; i--)
    {
        count++;
        if (count <= 4)
            answer = phone_number[i] + answer;
        else
            answer = '*' + answer;
    }
    return answer;
}