#include <iostream>

using namespace std;

int main()
{
    int n, sum = 1;
    cin >> n;

    cout << 1 ;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n == i)
                cout << " = ";
            else
            {
                sum += i;
                cout << " + "<< i;
            }
        }
    }
    cout << sum << endl;
    return 0;
}