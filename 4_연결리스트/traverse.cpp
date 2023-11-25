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

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    // addr은 이전 노드 번지
    // unused는 지금 새로 끼워넣을 노드 번지 
    // ...[unused]를 그냥 새로 끼워넣을 노드 자체라고 생각하면 편하다 
    // nxt[addr]은 예전 노드가 가리키던 원래 다음 노드의 번지를 가리킴, 
    // nxt[addr]을 그냥 원래의 다음 노드 자체라고 생각하면 편할듯 (이게 좋다)
    dat[unused] = num; // 새로 끼워 넣을 노드 data 작성 
    pre[unused] = addr; // 새로 끼워 넣을 노드의 이전 노드의 번지를 지정(addr)
    nxt[unused] = nxt[addr]; 
    // 이전 노드의 nxt를 그대로 받아옴, 이제 새 노드 dat[unused]의 다음 주소 nxt[unused]는 nxt[addr]이다
    if (nxt[addr] != -1) 
    // 연결 리스트의 맨 뒤에 노드를 추가하는 게 아니라면(이 조건 없으면 바로 밑에서 pre[-1]에 접근해버림)
        pre[nxt[addr]] = unused; 
        // 이전 노드의 원래 다음 노드의 이전을 원래 이전 노드가 아니라
        // unused로 변경
    nxt[addr] = unused; // 이전 노드의 다음 노드를 원래 노드에서 unused 번지 노드로 전환
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    // 지우려는 현재 노드 번지 addr의 이전 노드의 다음 노드를 현재 노드 번지 addr의 다음으로 바꿈
    if (nxt[addr] != -1) 
    // nxt[addr]이 -1라는 건 지우려는 현재 노드 번지 addr이 리스트의 마지막이라는 것을 의미
        pre[nxt[addr]] = pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1) [0 1]
  traverse();
  insert(0, 30); // 30(address=2) 10 [0, 2, 1]  
  traverse();
  insert(2, 40); // 30 40(address=3) 10 [0, 2, 3, 1]
  traverse();
  insert(1, 20); // 30 40 10 20(address=4) [0, 2, 3, 1, 4]
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5) [0, 2, 3, 1, 4, 5]
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}