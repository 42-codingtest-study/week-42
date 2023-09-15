#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

// 최솟값 찾기
int main() {
  fast;
  int N, L;
  // use deque
  deque<pair<int, ll> > dq;
  cin >> N >> L;
  ll _numbers[N + 1];
  memset(_numbers, 0, sizeof(_numbers));
  dq.clear();
  for (int i = 0; i < N; i++) cin >> _numbers[i];
  for (int i = 0; i < N; i++) {
    // 만약 덱의 크기가 0이 아니고
    // 덱의 끝 값이 현재의 값보다 크다면 덱의 끝 값을 제거
    while (dq.size() != 0 && dq.back().second > _numbers[i]) dq.pop_back();
    // 인덱스와 함께 값을 덱에 저장
    dq.push_back(make_pair(i, _numbers[i]));
    // 덱의 처음 값의 인덱스가 현재의 인덱스보다 L 이상이면 덱의 첫값을 제거
    if (i - dq.front().first >= L) dq.pop_front();
    // 현재의 첫값이 저장된 수중 가장 최솟값이 된다
    cout << dq.front().second << " ";
  }
}
