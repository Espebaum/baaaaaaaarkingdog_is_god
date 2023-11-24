#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

std::string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    int arr[26];
    fill(arr, arr+26, 0);
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}