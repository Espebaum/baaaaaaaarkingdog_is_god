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

long long A, B, C;

long long   solve(long long A, long long B, long long C) {
    if (B == 1) {
        return A % C;
    }
    long long val = solve(A, B/2, C);
    val = val * val % C;
    if (B % 2 == 0)
        return val;
    return val * A % C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;

    cout << solve(A, B, C);

    return 0;
}