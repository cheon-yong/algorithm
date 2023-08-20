#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> counts(3, 0);
    
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    
    queue<int> q2;
    q2.push(2);
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(2);
    q2.push(4);
    q2.push(2);
    q2.push(5);
    
    queue<int> q3;
    q3.push(3);
    q3.push(3);
    q3.push(1);
    q3.push(1);
    q3.push(2);
    q3.push(2);
    q3.push(4);
    q3.push(4);
    q3.push(5);
    q3.push(5);
    
    int len = answers.size();
    for (int i = 0; i < len; i++)
    {
        int t1 = q1.front();
        int t2 = q2.front();
        int t3 = q3.front();
        
        if (t1 == answers[i])
            counts[0]++;
        
        if (t2 == answers[i])
            counts[1]++;
        
        if (t3 == answers[i])
            counts[2]++;
        
        q1.pop();
        q1.push(t1);
        
        q2.pop();
        q2.push(t2);
        
        q3.pop();
        q3.push(t3);
    }
    
    int max = -1;
    for (int i = 0; i < counts.size(); i++)
    {
        if (max < counts[i])
            max = counts[i];
    }
    
    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] == max)
            answer.push_back(i + 1);
    }
    
    return answer;
}


// 다른 풀이
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> one = {1,2,3,4,5};
// vector<int> two = {2,1,2,3,2,4,2,5};
// vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

// vector<int> solution(vector<int> answers) {
//     vector<int> answer;
//     vector<int> they(3);
//     for(int i=0; i<answers.size(); i++) {
//         if(answers[i] == one[i%one.size()]) they[0]++;
//         if(answers[i] == two[i%two.size()]) they[1]++;
//         if(answers[i] == thr[i%thr.size()]) they[2]++;
//     }
//     int they_max = *max_element(they.begin(),they.end());
//     for(int i = 0; i< 3; i++) {
//         if(they[i] == they_max) answer.push_back(i+1);
//     }
//     return answer;
// }