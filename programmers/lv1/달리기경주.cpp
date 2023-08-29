#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> numbers;
    
    for (int i = 0; i < players.size(); i++)
    {
        numbers[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++)
    {
        int now = numbers[callings[i]];
        numbers[callings[i]] -= 1;
        numbers[players[now - 1]] += 1;
        
        swap(players[now], players[now - 1]);
    }
    
    answer = players;
    
    return answer;
}