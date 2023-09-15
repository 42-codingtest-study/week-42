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

// 좋다
int main() {
  fast;
  int N, _answer = 0;
  ll tmp, A[2001];
  memset(A, 0, sizeof(A));
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  // 예외처리
  if (N == 1) {
    cout << 0;
    return 0;
  }
  // 정렬
  sort(A, A + N);
  for (int i = 0; i < N; i++) {
    // 투 포인터 설정
    int _start = 0 == i ? 1 : 0, _end = N - 1 == i ? N - 2 : N - 1;
    while (_start < _end) {
      if (A[_start] + A[_end] > A[i]) _end--;
      // 같을 경우의 조건이 다양함
      else if (A[_start] + A[_end] == A[i]) {
        if (_start == i)
          _start++;
        else if (_end == i)
          _end--;
        else {
          _answer++;
          break;
        }
      } else
        _start++;
    }
  }
  cout << _answer;
}
