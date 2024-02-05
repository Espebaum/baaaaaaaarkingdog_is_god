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

int TC, N, M, W;
int S, E, T;
int d[505][505];

void    Floyd()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (d[j][k] > d[j][i] + d[i][k])
                    d[j][k] = d[j][i] + d[i][k];
            }
        }
    }
}

void    solve()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                d[i][j] = INF;
        }
    }

    for (int i = 1; i <= M; i++) {
        cin>>S>>E>>T;
        d[S][E] = min(d[S][E], T);
    }

    for (int i = 1; i <= W; i++) {
        cin>>S>>E>>T;
        d[S][E] = min(d[S][E], -T);
    }

    Floyd();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    


    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;

    while (TC--)
    {
        cin >> N >> M >> W;
        solve();
    }
    

    return 0;
}