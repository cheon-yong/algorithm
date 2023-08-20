#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int area = brown + yellow;
    
    for (int i = 3; i <= area / 2; i++)
    {
        if (area % i != 0)
            continue;
        
        int w = i;
        int h = area / i;
        
        if ((w * 2 + h * 2) - 4 == brown)
        {
            answer.push_back(h);
            answer.push_back(w);
            break;
        }
    }
    
    return answer;
}