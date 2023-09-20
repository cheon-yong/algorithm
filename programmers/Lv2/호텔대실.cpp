#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int room[1451] = {0, };
    vector<vector<int>> book_number;
    
    for (int i = 0; i < book_time.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < book_time[i].size(); j++)
        {
            string hourStr = book_time[i][j].substr(0, 2);
            if (hourStr[0] == '0')
                hourStr = hourStr.substr(1);
            
            string minStr = book_time[i][j].substr(3, 2);
            if (minStr[0] == '0')
                minStr = minStr.substr(1);
            
            int hour = stoi(hourStr);
            int min = stoi(minStr);
            int time = hour * 60 + min;
            if (j == 1)
                time += 10;
            
            v.push_back(time);
        }
        book_number.push_back(v);
        for (int j = book_number[i][0]; j < book_number[i][1]; j++)
            room[j]++;
    }
    for (int i = 0; i < 1451; i++)
    {
        answer = max(answer, room[i]);
    }
    
    return answer;
}