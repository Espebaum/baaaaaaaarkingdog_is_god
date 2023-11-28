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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)s
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
}

void pop(){
    pos--;
}

int top(){
    int tmp = pos - 1;
    return (dat[tmp]);
}

void test(){
  push(5); 
  push(4); 
  push(3);
  cout << top() << '\n'; // 3

  pop();
  pop();
  cout << top() << '\n'; // 5
  
  push(10); 
  push(12);
  cout << top() << '\n'; // 12
  
  pop();
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}