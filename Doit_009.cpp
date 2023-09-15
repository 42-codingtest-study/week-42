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

// DNA 비밀번호
int main() {
  fast;
  int S, P, _pass[4], _curr[4];
  string DNA;
  memset(_pass, 0, sizeof(_pass));
  memset(_curr, 0, sizeof(_curr));
  cin >> S >> P >> DNA;
  for (int i = 0; i < 4; i++) cin >> _pass[i];
  // 초기값을 현재 배열에 추가
  int _start = 0, _end = P, _answer = 0;
  for (int i = 0; i < P; i++) {
    if (DNA[i] == 'A')
      _curr[0]++;
    else if (DNA[i] == 'C')
      _curr[1]++;
    else if (DNA[i] == 'G')
      _curr[2]++;
    else
      _curr[3]++;
  }
  if (_pass[0] <= _curr[0] && _pass[1] <= _curr[1] && _pass[2] <= _curr[2] &&
      _pass[3] <= _curr[3])
    _answer++;
  // 슬라이딩 윈도우
  while (_end < S) {
    if (DNA[_end] == 'A')
      _curr[0]++;
    else if (DNA[_end] == 'C')
      _curr[1]++;
    else if (DNA[_end] == 'G')
      _curr[2]++;
    else
      _curr[3]++;
    if (DNA[_start] == 'A')
      _curr[0]--;
    else if (DNA[_start] == 'C')
      _curr[1]--;
    else if (DNA[_start] == 'G')
      _curr[2]--;
    else
      _curr[3]--;
    if (_pass[0] <= _curr[0] && _pass[1] <= _curr[1] && _pass[2] <= _curr[2] &&
        _pass[3] <= _curr[3])
      _answer++;
    _end++;
    _start++;
  }
  cout << _answer;
}
