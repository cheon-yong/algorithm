#include <iostream>

using namespace std;

int answer[41] = {0, 1, 1};
int main()
{
    for (int i = 3 ; i < 41; i++)
    {
        answer[i] = answer[i-1] + answer[i-2];
    }

    int T;
    cin >> T;
    for (int i = 0 ; i < T; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
            cout << 1 << " " << 0 << endl;
        else if (n == 1)
            cout << 0 << " " << 1 << endl;
        else
        cout << answer[n-1] << " " << answer[n] << endl;
    }
    

    return 0;    
}