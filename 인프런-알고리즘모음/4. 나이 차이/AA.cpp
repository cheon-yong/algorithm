#include <iostream>

using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0 ; i < n; i++)
    {
        for (int j = i ; j < n; j++)
        {
            int diff = arr[i] - arr[j];
            if (diff < 0)
                diff *= -1;
            if (diff > max)
                max = diff;
        }
    }
    cout << max << endl;
    return 0;
}