#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;
    vector<int> ram(s);
    int *job = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> job[i];
    }
;
    for (int i = 0; i < n; i++)
    {
        bool contain = false;
        int temp = -1;
        int j = 0;
        for (j = 0; j < ram.size(); j++)
        {
            if (ram[j] == job[i])
            {
                contain = true;
                temp = ram[j];
                break;
            }
        }

        if (contain)
        {
            while (j > 0)
            {
                ram[j] = ram[j-1];
                j--;
            }
            ram[j] = temp;
        }
        else
        {
            ram.insert(ram.begin(), job[i]);
            if (ram.size() > s)
            {
                ram.pop_back();
            }
        }
    }
    for (int i = 0; i < ram.size(); i++)
    {
        cout << ram[i] << " ";
    }
    cout << endl;
    return 0;
}