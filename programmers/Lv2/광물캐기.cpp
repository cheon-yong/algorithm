#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 99999999;
int len = 0;

vector<string> globalMinerals;

void usePick(int usingPick, int count, int weight, vector<int> picks)
{
    // Check left picks
    int leftPick = 0;
    for (int i = 0; i < picks.size(); i++)
    {
        leftPick += picks[i];
    }
    
    if (leftPick == 0)
    {
        answer = min(answer, weight);
        return;
    }
    
    if (picks[usingPick] == 0)
    {
        return;
    }
    
    // use pick
    int limit = min(len, (count + 1) * 5);
    for (int i = count * 5; i < limit; i++)
    {
        if (usingPick == 0)
        {
            weight += 1;
        }
        else if (usingPick == 1)
        {
            if (globalMinerals[i] == "diamond")
                weight += 5;
            else
                weight += 1;
        }
        else
        {
            if (globalMinerals[i] == "diamond")
                weight += 25;
            else if (globalMinerals[i] == "iron")
                weight += 5;
            else
                weight += 1;
        }
    }
    
    picks[usingPick] -= 1;
    count++;
    // use next pick
    for (int i = 0; i < picks.size(); i++)
    {
        usePick(i, count, weight, picks);
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    globalMinerals = minerals;
    
    int pickCount = 0;
    for (int i = 0; i < picks.size(); i++)
    {
        pickCount += picks[i] * 5;
    }
    
    len = min((int)minerals.size(), pickCount);
    for (int i = 0; i < picks.size(); i++)
    {
        usePick(i, 0, 0, picks);
    }
    
    
    return answer;
}