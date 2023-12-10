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

int N, r, c;

int func(int N, int r, int c)
{
    if (N == 0)
        return 0;
    int half = 1 << (N - 1);
    if (r < half && c < half)
        return func(N - 1, r, c);
    if (r < half && c >= half)
        return half*half + func(N - 1, r, c - half);
    if (r >= half && c < half)
        return 2*half*half + func(N - 1, r - half, c);
    return (3*half*half + func(N - 1, r - half, c - half));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> r >> c;

    cout << func(N, r, c);

    return 0;
}