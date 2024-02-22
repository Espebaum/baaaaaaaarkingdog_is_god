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

int A, B, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>A>>B>>C;
    cout << (A+B)%C << '\n';
    cout << ((A%C) + (B%C))%C << '\n';
    cout << (A*B)%C << '\n';
    cout <<((A%C)*(B%C))%C <<'\n';
    return 0;
}