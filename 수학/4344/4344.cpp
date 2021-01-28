/*
    백준 4344번 문제 평균
    작성자 : cheon-yong <yes1312@naver.com>
    입력받은 수들로부터 평균값을 구하고 
    평균값을 초과한 수들의 비율을 출력한다.
*/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        float arr[n];
        float sum = 0;;
        for (int i=0; i<n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        float avg = sum / n;
        float cnt = 0;
        for (int i=0; i<n; i++)
        {
            if (arr[i] > avg)
                cnt++;    
        }
        printf("%.3f%%\n", cnt/n*100);
    }
    return 0;
}