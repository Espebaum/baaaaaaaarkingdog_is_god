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

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int vis[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int mx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            mx = max(mx, tmp);
        }
    }

    queue< pair<int, int> > q;
    vector<int> v;
    int area;

    for (int num = 0; num <= mx; num++)
    {
        area = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] > num && !vis[i][j])
                {
                    area++;
                    vis[i][j] = 1;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front(); q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                                continue;
                            if (vis[nx][ny] || board[nx][ny] <= num)
                                continue;
                            vis[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        for (int h = 0; h < N; h++)
            for (int l = 0; l < N; l++)
                vis[h][l] = 0;
        v.push_back(area);
    }   
    int res = 0; 
    for (int i = 0; i < v.size(); i++){
        res = max(res, v[i]);
    }
    cout << res;
    return 0;
}