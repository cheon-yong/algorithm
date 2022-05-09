#include "iostream"

using namespace std;

int main()
{
    int n;
    int *numbers;
    cin >> n;

    numbers = new int[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int min = 1000000, max = -1000000;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] >= max)
            max = numbers[i];
        if (numbers[i] <= min)
            min = numbers[i];
    }
    cout << min << " " << max << endl;
    return 0;
}