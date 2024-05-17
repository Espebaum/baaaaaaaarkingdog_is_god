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

int board[1010][1010];
int T, X, Y, x, y;
vector<int> res;

void    check(int r, int c, int ans)
{
    // cout << "r: " << r << " c: " << c << '\n';
    if (r > X - 1) {
        res.push_back(ans);
        return ;
    } 
    if (c > Y - 1) {
        check(r + 1, 0, ans);
    }
    else if (board[r][c] == 0) {
        if (r + x < X && c + y < Y && board[r+x][c+y] != 1) {
            board[r][c] = 1;
            board[r+x][c+y] = 1;
            ans += 1;
            check(r, c + 1, ans);
            board[r+x][c+y] = 1;
            board[r][c] = 1;
            ans -= 1;
        } 
        else {
            board[r][c] = 1;
            ans += 1;
            check(r, c + 1, ans);
            board[r][c] = 0;
            ans -= 0;
        }
    } else
        check(r, c + 1, ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin>>X>>Y>>x>>y;
        check(0, 0, 0);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }   cout << '\n';
        for (int i = 0; i < X; i++)
            fill(board[i], board[i]+Y, 0);
        res.clear();
    }
    return 0;
}