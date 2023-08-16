#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int num)
{
    if (num == 0 || num == 1)   
        return false;
    
    int len = sqrt(num);
    for(int i = 2; i <= len; i++)
    {
        if(num % i == 0)
            return false;
    }
        
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> number;
    vector<int> stringNum;
        
    int len = numbers.size();
    for (int i = 0; i < len; i++)
    {
        number.push_back(numbers[i]);
    }
    
    sort(number.begin(), number.end());
    do
    {
        string str = "";
        for(int i = 0; i < number.size(); i++){
            str.push_back(number[i]);
            stringNum.push_back(stoi(str));
        }
    }
    while(next_permutation(number.begin(), number.end()));
    
    sort(stringNum.begin(), stringNum.end());
    stringNum.erase(unique(stringNum.begin(), stringNum.end()), stringNum.end());
    
    for (int i = 0; i < stringNum.size(); i++)
    {
        if (isPrime(stringNum[i]))
            answer++;
    }
    
    return answer;
}