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
int board[500005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    sort(board, board + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int target; cin >> target;
        int st = 0;
        int en = N;
        while (st < en) {
        int mid = (st + en) / 2;
        if (board[mid] >= target)
            en = mid;
        else // board[mid] == target일때 오른쪽을 당김
            st = mid + 1;
        }
        int l = st; // 가장 왼쪽
    
        st = 0;
        en = N;
        while (st < en) {
            int mid = (st + en) / 2;
            if (board[mid] > target)
                en = mid;
            else // board[mid] == target일때 왼쪽을 당김
                st = mid + 1;
        }
        int r = st; // 가장 오른쪽
        cout << r - l << ' ';
    }

    return 0;
}