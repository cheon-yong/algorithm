#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int card1Index = 0;
    int card2Index = 0;
    int goalIndex = 0;
    while (goalIndex < goal.size())
    {
        bool change = false;
        if (goal[goalIndex] == cards1[card1Index])
        {
            goalIndex++;
            card1Index++;
            change = true;
        }
            
        if (goal[goalIndex] == cards2[card2Index])
        {
            goalIndex++;
            card2Index++;
            change = true;
        }
        
        if (change == false)
            return "No";
    }
    
    return "Yes";
}