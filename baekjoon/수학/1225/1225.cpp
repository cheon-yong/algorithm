#include <iostream>

using namespace std;

int main ()
{
    string n, m;
    cin >> n >> m;

    long long res = 0;
    for (int i = 0; i < n.length(); i++)
    {
        for (int j = 0; j < m.length(); j++)
        {
            res += (int)(n[i] - '0') * (int)(m[j] - '0');
        }
    }
    cout << res << endl;
    return 0;
}