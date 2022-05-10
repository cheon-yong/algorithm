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

    for (int i = 0; i < n; i++)
    {
        int maxindex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > arr[maxindex])
                maxindex = j;
        }
        int temp = arr[i];
        arr[i] = arr[maxindex];
        arr[maxindex] = temp;
    }

    int count = 1;
    for (int i = 1 ; i < n; i++)
    {
        if (arr[i-1] > arr[i])
            count++;
        
        if (count == 3)
        {
            cout << arr[i] << endl;
            break;
        }
            
    }
    return 0;
}