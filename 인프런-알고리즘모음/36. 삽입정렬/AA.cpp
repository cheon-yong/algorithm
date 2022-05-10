#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1 ; i < n; i++)
    {
        int temp = arr[i];
        int lastIndex = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j+1] = arr[j];
            else
            {
                lastIndex = j + 1;
                break;  
            }
        }
        arr[lastIndex] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}