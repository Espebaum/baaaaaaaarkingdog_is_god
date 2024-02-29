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
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
int board[303][303];
int vis[303][303];
vector<tuple<int,int,int>>vt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int turn = 0;
    // while (1)
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j]) {
                    int cx = i; int cy = j; int point = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (board[nx][ny] == 0)
                            point++;
                    }
                    vt.push_back({i, j, point});
                }
            }
        }
        cout << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << board[i][j] << ' ';
            } cout << '\n';
        }

        turn++;
    }
    cout << turn;
    return 0;
}
