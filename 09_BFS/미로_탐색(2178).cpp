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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int dist[101][101];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }

    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);

    queue< pair<int, int> > q;
    dist[0][0] = 0;
    q.push(make_pair(0, 0));

    while(!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != 1)
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << dist[n - 1][m - 1] + 1;
    return 0;
}