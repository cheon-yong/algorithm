#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;


unordered_map<string, string> accounts;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for (string line : record)
    {
        stringstream ss(line);
        string work, uid, name;
        ss >> work >> uid >> name;
        
        if (work == "Enter" || work == "Change")
        {
            accounts[uid] = name;
        }
    }
    
    for (string line : record)
    {
        stringstream ss(line);
        string work, uid, name;
        ss >> work >> uid >> name;
        
        string s = "";
        if (work == "Enter")
        {
            s = accounts[uid] + "님이 들어왔습니다.";
        }
        else if (work == "Leave")
        {
            s = accounts[uid] + "님이 나갔습니다.";
        }
        
        if (s.empty() == false)
        {
            answer.push_back(s);
        }
    }
    
    return answer;
}