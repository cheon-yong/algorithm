/*
    ���� 1929�� ���� ���
    �ۼ��� : cheon-yong <yes1312@naver.com>
    
    ����
    * M �̻� N ������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

    �Է�
    * ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.

    ���

    * �� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/

#include <iostream>

using namespace std;

bool checkPrime(int num)
{
    for(int i = 0; i < num / 2; i++)
    {
        if (num % i != 0)
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = n; i <= m; i++)
    {
        if (checkPrime(i))
            cout << i << endl;
    }
    return 0;
}