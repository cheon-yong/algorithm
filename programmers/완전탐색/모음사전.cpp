#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};

void findWord(string word)
{
    cnt++;
    
    if (word == target)
    {
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5)
        return;
    
    for (int i = 0; i < 5; i++)
    {
        findWord(word + vowels[i]);
    }
}

int solution(string word) {
    target = word;
    findWord("");
    
    return answer;
}


// 다른 답안 1
// #include <assert.h>
// #include <string>
// #include <vector>

// using namespace std;

// int solution(string word)
// {
//     const int weights[5] = { 781, 156, 31, 6, 1 };
//     int answer = 0;
//     for (int i = 0; i < word.length(); ++i)
//     {
//         int current;
//         switch (word[i])
//         {
//         case 'A':
//             current = 0;
//             break;
//         case 'E':
//             current = 1;
//             break;
//         case 'I':
//             current = 2;
//             break;
//         case 'O':
//             current = 3;
//             break;
//         case 'U':
//             current = 4;
//             break;
//         default:
//             assert(false);
//         }
//         ++answer;
//         answer += current * weights[i];
//     }
//     return answer;
// }

// 다른 답안 2

// #include <string>

// using namespace std;

// int solution(string word) {
//     string v = string("AEIOU");
//     int a = word.size();

//     for(int i = 0, b = 1; i < word.size(); i++, b *= 5)
//         a += v.rfind(word[i]) * 781 / b;

//     return a;
// }