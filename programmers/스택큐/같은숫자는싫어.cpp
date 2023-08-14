#include <vector>
#include <iostream>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {   
        if (answer[answer.size() - 1] == arr[i])
            continue;
        
        answer.push_back(arr[i]);
    }

    return answer;
}

// ÂªÀº Ç®ÀÌ
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// vector<int> solution(vector<int> arr) 
// {

//     arr.erase(unique(arr.begin(), arr.end()),arr.end());

//     vector<int> answer = arr;
//     return answer;
// }

