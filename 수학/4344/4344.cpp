/*
    ���� 4344�� ���� ���
    �ۼ��� : cheon-yong <yes1312@naver.com>
    �Է¹��� ����κ��� ��հ��� ���ϰ� 
    ��հ��� �ʰ��� ������ ������ ����Ѵ�.
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