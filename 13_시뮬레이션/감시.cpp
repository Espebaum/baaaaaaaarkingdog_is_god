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

int N, M;
int board[70][70];
int area;

void    solve(int x, int y)
{
    // 0 north, 1 south, 2 west, 3 east
    for (int i = x; i < N; i++) {
        for (int j = y; j < M; j++) {
            if (board[i][j] >= 1 && board[i][j] <= 5)
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0);

    return 0;
}