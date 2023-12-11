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

//|1|4|5|
int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> K;
    list<int>   l;
    vector<int> v;
    
    for (int i = 1; i <= N; i++)
        l.push_back(i);

    list<int>::iterator it = l.begin();

    for (int i = 0; i < N; i++) 
    {
        for (int i = 0; i < K - 1; i++) 
        {
            it++;
            if (it == l.end())
                it = l.begin();
        }
        v.push_back(*it);
        it = l.erase(it);
        if (it == l.end())
            it = l.begin();
    }

    cout << "<";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}