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

int tc;
int M, N, K; // M 가로길이, N 세로길이
int board[55][55];
int vis[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void    solve()
{
    cin >> M >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    while (K--)
    {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }

    queue< pair<int, int> > q;
    int bug = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (board[i][j] == 0 || vis[i][j])
                continue;
            bug++;
            q.push(make_pair(i, j));
            vis[i][j] = 1;
            // cout << "i : " << i << " j : " << j << endl;
            while (!q.empty())
            {
                pair<int, int> cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1; 
                    q.push(make_pair(nx, ny));
                }
            }   
        }
    }
    cout << bug << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--){
        solve();
    }

    return 0;
}