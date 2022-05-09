/*
    ���� 2606�� ���� ���̷���
    �ۼ��� : cheon-yong <yes1312@naver.com>
    �׷����� �־����� �� 1�� ��ǻ�ͷκ��� �����Ǵ� ��ǻ���� ���� ���Ѵ�.
*/

#include <iostream>

using namespace std;

int map[101][101];
bool visit[101];
int n;
void dfs (int start)
{
    for (int i=1; i<=n; i++)
    {
        if(visit[i] != true && map[start][i] == 1)
        {
            visit[i] = true;
            dfs(i);
        }
    }
}
int main()
{
    int e;
    cin >> n >> e;
    for (int i=0; i<e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        map[n1][n2] = 1;
        map[n2][n1] = 1;
    }
    visit[1] = true;
    dfs(1);
    int sum = 0;
    for (int i=1; i<=n; i++)
    {
        if (visit[i] == true)
            sum++;
    }
    cout << sum-1 << endl;
    return 0;
}