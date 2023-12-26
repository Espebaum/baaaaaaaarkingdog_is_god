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

void    check1(int r, int c)
{
    vector<int> v;
    int way1 = 0;
    int way2 = 0;
    int way3 = 0;
    int way4 = 0;
    // 위 체크 (1)
    int up = r;
    while (up > 0) {
        up--;
        if (board[up][c] == 6)
            break ;
        way1++;
    }
    v.push_back(way1);
    // 아래 체크 (2)
    int down = r;
    while (down < N - 1) {
        down++;
        if (board[down][c] == 6)
            break ;
        way2++;
    }
    v.push_back(way2);
    // 왼쪽 체크 (3)
    int left = c;
    while (left > 0) {
        left--;
        if (board[r][left] == 6)
            break ;
        way3++;
    }
    v.push_back(way3);
    // 오른쪽 체크 (4)
    int right = c;
    while (right < M - 1) {
        right++;
        if (board[r][right] == 6)
            break ;
        way4++;
    }
    v.push_back(way4);
    // sort(v.begin(), v.end());
    for (int i = 0; i < 4; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void    solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1)
                check1(i, j);
            // else if (board[i][j] = 2)
            //     check2(i, j);
            // else if (board[i][j] = 3)
            //     check3(i, j);
            // else if (board[i][j] = 4)
            //     check4(i, j);
            // else if (board[i][j] = 5)
            //     check5(i, j);
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

    solve();

    return 0;
}