/*
    ���� 1546�� ���� ���
    �ۼ��� : cheon-yong <yes1312@naver.com>
    �� �������� ����� ������ ���Ǹ� ������.
    ���� �� �ִ밪�� M�̶�� ���� �� �Է��� ������ ����/M*100���� ���� �����ϰ� 
    ���� ������ ���� �ִ밪�� ���Ѵ�.
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