#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> total;
    map<string, int> park; 
    for (string record : records)
    {
        string timeStr = record.substr(0, 5);
        string carNum = record.substr(6, 4);
        string inout = record.substr(10);
        
        int time = stoi(timeStr.substr(0,2)) * 60 + stoi(timeStr.substr(3,2));
        
        
        // 출차
        if (inout.find("OUT") != string::npos)
        {
            int duration = time - park[carNum];
            if (total.find(carNum) == total.end())
                total[carNum] = duration;
            else
                total[carNum] += duration;
            
            park[carNum] = -1;
        }
        // 입차
        else
        {
            park[carNum] = time;
        }
    }
    
    for (auto elem : park)
    {
        if (elem.second != -1)
            total[elem.first] += 1439 - elem.second;
    }
    
    // fees = { 기본시간, 기본요금, 단위시간, 단위요금 }
    for (auto elem : total)
    {
        if (fees[0] >= elem.second)
        {
            answer.push_back(fees[1]);
        }
        else
        {
            int realTime = elem.second - fees[0];
            if (realTime % fees[2] == 0)
            {
                answer.push_back(fees[1] + ((realTime / fees[2]) * fees[3]));
            }
            else
            {
                answer.push_back(fees[1] + ((realTime / fees[2]) * fees[3]) + fees[3]);
            }
        }
    }
    return answer;
}