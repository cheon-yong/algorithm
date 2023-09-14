#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    int minValue = arr[0];
    int index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
            index = i;
        }
    }
    
    answer.erase(answer.begin() + index);
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}