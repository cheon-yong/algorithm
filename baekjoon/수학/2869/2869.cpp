#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;

    int day = v / (a - b);
    if (v % (a - b) > 0)
        day++;

    cout << day << endl;

    return 0;
}