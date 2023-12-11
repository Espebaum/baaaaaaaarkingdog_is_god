#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, area;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[101];
int vis[101][101];

void    w_bfs(char c, int i, int j)
{
    area++;
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    vis[i][j] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; 
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == c || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }   
    }
}

void    bfs(char c, int i, int j)
{
    area++;
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    vis[i][j] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; 
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] != c || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }   
    }
}

void    weak()
{
    area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j])
                continue;
            if (board[i][j] == 'R' || board[i][j] == 'G')
                w_bfs('B', i, j);
            else if (board[i][j] == 'B')
                bfs('B', i, j);
        }
    }
    cout << area;
}

void    normal()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j])
                continue;
            bfs(board[i][j], i, j);
        }
    }
    cout << area << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    normal();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = 0;
    weak();

    return 0;
}