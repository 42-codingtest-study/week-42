#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  // 투 포인터 설정
  int N, _start = 0, _end = 1, _sum = 1, _answer = 0;
  cin >> N;
  // 투 포인터 조건
  while (_start != _end) {
    if (_sum < N) {
      _end++;
      _sum += _end;
    } else if (_sum == N) {
      _answer++;
      _end++;
      _sum += _end;
    } else {
      _sum -= _start;
      _start++;
    }
  }
  // N이 1이 아닌경우, 투 포인터가 N까지 갈 수 없어 답에 1을 더해준다.
  cout << _answer + (N == 1 ? 0 : 1);
}
