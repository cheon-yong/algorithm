#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int temp = x;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    answer = temp % sum == 0 ? true : false;
    return answer;
}