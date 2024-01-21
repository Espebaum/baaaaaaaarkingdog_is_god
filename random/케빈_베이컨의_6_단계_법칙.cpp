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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int N, M;
int board[101][101];
int vis[101];
int ans[101][101];

int dfs(int k, int dest, int ans)
{
    if (vis[k] == 1) {
        return ans;
    }
    if (k == dest) {
        return ans;
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[k] && board[k][i] == 1) {
            if (i == dest) {
                continue;
            }
            vis[k] = 1;
            return dfs(i, dest, ans++);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int x, y; 
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue ;
            ans[i][j] = dfs(i, j, 0);
        }
        for (int i = 1; i <= N; i++)
            vis[i] = 0;
    }
    cout<< ans[1][2];
    return 0;
}