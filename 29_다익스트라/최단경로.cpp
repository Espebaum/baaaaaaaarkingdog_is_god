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

int v, e, st;
vector<pair<int,int>> adj[20005];
bool fix[20005];
int  d[20005];
int V = 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>v>>e>>st;
    fill(d, d+v+1, INF);

    for (int i = 0; i < e; i++) {
        int u, v, w;cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int,int>>> pq;

    d[st] = 0;
    pq.push(d[st], st);
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        if (d[cur].second != d[cur].first)
            continue ;
    }

    return 0;
}