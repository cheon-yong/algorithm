/*
    백준 1546번 문제 평균
    작성자 : cheon-yong <yes1312@naver.com>
    이 문제에서 평균은 문제의 정의를 따른다.
    점수 중 최대값을 M이라고 했을 때 입력한 점수를 점수/M*100으로 새로 정의하고 
    새로 정의한 값의 최대값을 구한다.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    float sum = 0, max = 0;
    float arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i=0; i<n; i++)
    {
        arr[i] = (arr[i]/max*100);
        sum += arr[i];
    }
    cout << (float)(sum / n) << endl;
    return 0;
}