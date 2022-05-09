#include "iostream"

using namespace std;


long getFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * getFactorial(n - 1);        
}



int main()
{
    int n;
    cin >> n;

    int res = getFactorial(n);
    cout << res << endl;
    return 0;
}