/*
    ���� 1260�� ���� DFS�� BFS
    �ۼ��� : cheon-yong <yes1312@naver.com>

    ����
    �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
    ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
    �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 
    ���� ��ȣ�� 1������ N�������̴�.

    �Է�
    ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
    ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. 
    � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. 
    �Է����� �־����� ������ ������̴�.

    ���
    ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.
*/

#include <iostream>
#include <queue>

using namespace std;

int **graph;
bool *visit;
int N, M, V;
queue<int> q;

void DFS(int V)
{
    if (visit[V])
        return;
    
    visit[V] = true;
    cout << V << " ";
    for (int i = 1; i < N + 1; i++)
    {
        if (graph[V][i] == 1)
        {
            DFS(i);
        }
            
    }
        
}

void BFS(int V)
{
    q.push(V);
    visit[V] = true;
    while (!q.empty())
    {
        int next = q.front();
        cout << next << " ";
        q.pop();
        for (int i = 1; i < N + 1; i++)
        {
            if (graph[next][i] == 1 && !visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    // ������ �� + 1 ��ŭ 2���� �迭 ����
    graph = new int*[N+1];
    visit = new bool[N+1];
    for (int i = 0; i < N + 1; i++)
        graph[i] = new int[N+1];

    for (int i = 0; i < N + 1; i++)
    {
        visit[i] = false;
        for (int j = 0; j < N + 1; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1][p2] = 1;
        graph[p2][p1] = 1;
    }

    DFS(V);
    for (int i = 0; i < N + 1; i++)
    {
        visit[i] = false;
    }
    cout << endl;
    BFS(V);
    return 0;
}
