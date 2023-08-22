#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    int maxValue = 0;
    for (int i = 0; i < len; i++)
    {
        maxValue += elements[i];
        elements.push_back(elements[i]);
    }
    
    vector<int> values(maxValue +1, 0);
    values[maxValue] = 1;
    answer = 1;
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < elements.size() - i; j++)
        {
            int sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += elements[j + k];
            }
            if (values[sum] == 0)
            {
                values[sum] = 1;
                answer++;
            }
        }
    }
    
    return answer;
}

// ÂªÀº ´ä

// #include <string>
// #include <vector>
// #include <set>

// using namespace std;

// int solution(vector<int> elements) {
//     int answer = 0;
//     set<int> values;
//     int len = elements.size();
    
//     for (int i = 0; i < len; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < i + len; j++)
//         {
//             sum += elements[j % len];
//             values.insert(sum);
//         }
//     }
    
//     answer = values.size();
//     return answer;
// }
