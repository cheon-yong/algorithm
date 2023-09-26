#include <iostream>

using namespace std;

int arr[15][15] = {0};

int getNumber(int a, int b)
{
    if (a == 0)
    {
        arr[0][b] = b;
        return b;
    }

    if (arr[a][b] == 0)
    {
        int sum = 0;
        for (int i = 1; i <= b; i++)
        {
            sum += getNumber(a-1 , i);
        }

        arr[a][b] = sum;
    }

    return arr[a][b];
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        int k, n;
        cin >> k >> n;
        cout << getNumber(k, n) << endl;
    }
    return 0;
}