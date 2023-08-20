#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int len = citations.size();
    
    sort(citations.begin(), citations.end(), less<int>());
    int max = citations[len - 1];
    
    // h�� hindex �ĺ�
    for (int h = 0; h < max; h++)
    {
        for (int i = 0; i < len; i++)
        {
            if (h > citations[i])
                continue;
            
            if (len - i >= h)
                answer = h;
            else
                break;
        }
    }
    return answer;
}

// ª�� Ǯ��
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> citations) {
//     sort(citations.begin(), citations.end(), greater<int>());

//     for (int i = 0; i < citations.size(); ++i) {
//         if (citations[i] < i + 1) {
//             return i;
//         }
//     }

//     return citations.size();
// }
