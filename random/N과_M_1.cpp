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
int arr[10];
int isused[10];

void    solve(int k)
{
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        } cout << '\n';
        return;
    }

    int st = 1;
    if (k != 0)
        st = arr[k - 1] + 1;

    for (int i = st; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            solve(k+1);
            isused[i] = 0;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    solve(0);

    return 0;
}