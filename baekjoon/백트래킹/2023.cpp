#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int N;
bool isPrime(int num)
{
    if (num < 2)
        return false;

    int len = sqrt(num);
    for (int i = 2; i <= len; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void solve(int num, int cnt) {
    if (cnt == N)
    {
        cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        int next = num * 10 + i;
        if (isPrime(next))
            solve(next, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    solve(0, 0);
    return 0;
}