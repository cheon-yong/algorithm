/*
    백준 1260번 문제 DFS와 BFS
    작성자 : cheon-yong <yes1312@naver.com>

    문제
    그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
    단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
    더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
    정점 번호는 1번부터 N번까지이다.

    입력
    첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
    다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
    어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
    입력으로 주어지는 간선은 양방향이다.

    출력
    첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
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

    // 정점의 수 + 1 만큼 2차원 배열 생성
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
