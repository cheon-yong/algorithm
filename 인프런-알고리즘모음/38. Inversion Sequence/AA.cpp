#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int *res = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = i+1;
    }
    int i = n - 1;
    // arr 53402110
    // res 12348567
    while(i >= 0)
    {
        bool correct = false;
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (res[j] > res[i])
                count++;
        }
        if (count == arr[res[i]-1])
        {
            i--;
            continue;
        }
            

        if (count > arr[res[i]-1])
        {
            int temp = res[i];
            res[i] = res[i-1];
            res[i-1] = temp;
        }

        if (count < arr[res[i]-1])
        {
            int temp = res[i];
            res[i] = res[i+1];
            res[i+1] = temp;
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}