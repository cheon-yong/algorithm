/*
    백준 1929번 문제 평균
    작성자 : cheon-yong <yes1312@naver.com>
    
    문제
    * M 이상 N 이하의 소수를 모두 출력하는 프로그램을 작성하시오.

    입력
    * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

    출력

    * 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
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