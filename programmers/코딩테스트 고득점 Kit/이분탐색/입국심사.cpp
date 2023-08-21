#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = (long long)times.back() * n;
    long long answer = 0;

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long count = 0;
        for (int i = 0; i < times.size(); i++)
        {
            count += (mid / (long long) times[i]);
        }
        
        if (count >= n)
        {
            max = mid - 1;
            answer = mid;
        }
        else
        {
            min = mid + 1;
        }
    }
    
    return answer;
}