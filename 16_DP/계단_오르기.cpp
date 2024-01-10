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
using namespace std;

int N;
int st[303];
int dp[303][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> st[i];
    }

    if (N == 1) {
        cout << st[1];
        return 0;
    }

    dp[1][1] = st[1]; dp[1][2] = 0;
    dp[2][1] = st[2]; dp[2][2] = st[1] + st[2];

    for (int i = 3; i <= N; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + st[i];
        dp[i][2] = dp[i - 1][1] + st[i];
    }
    cout << max(dp[N][1], dp[N][2]);

    return 0;
}