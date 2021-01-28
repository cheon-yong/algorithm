#include <iostream>

using namespace std;

int n;
int map[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int max_val = 0;

void get_max()
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (map[i][j] > max_val)
                max_val = map[i][j];
        }
    }
}

void up()
{

}


void rotate()
{
    int temp[20][20];
    for (int i = 0; i<n; i++)
        for (int j=0; j<n; j++)
            temp[i][j] = map[i][j];

    for (int i = 0; i<n; i++)
        for (int j=0; j<n; j++)
            map[i][j] = temp[n-1-j][i];
}

void solve(int count)
{
    count++;
    if (count > 5)
    {
        get_max();
        return ;
    }
    for (int i=0; i<4; i++)
    {    
        rotate();
        up();
        solve(count);
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    int count = 0;
    //solve (count);
    
    return 0;
}