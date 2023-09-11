#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    int length = sequence.size() + 1;
    int start = 0;
    int sum = sequence[0];
    int end = 0;
    
    while (start <= end && end < sequence.size())
    {
        if (sum < k)
        {
            end++;
            sum += sequence[end];
            continue;
        }
        else if (sum == k)
        {
            if (length > end - start + 1)
            {
                answer[0] = start;
                answer[1] = end;
                length = end - start + 1;
            }
            
            else if (length == end - start + 1)
            {
                if (answer[0] > start)
                {
                    answer[0] = start;
                    answer[1] = end;
                }
            }
        }
        
        sum -= sequence[start];
        start++;
    }
    
    return answer;
}

