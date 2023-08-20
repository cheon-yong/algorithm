#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    bool isfinish = false;
    while(!isfinish)
    {
        int count = 0;
        int iszero = 0;
        for (int i = 0; i < progresses.size(); i++)
        {
            if (progresses[i] > 0)
                progresses[i] += speeds[i];
            else
                iszero++;
            
            if (progresses[i] >= 100)
            {
                if (i > 0)
                {
                    if (progresses[i - 1] == 0)
                    {
                        progresses[i] = 0;
                        count++;
                    }
                }
                else 
                {
                    progresses[i] = 0;
                    count++;
                }
            }
        }
        if (count != 0)
                answer.push_back(count);
        if (iszero == progresses.size())
                isfinish = true;
        
    }
    return answer;
}