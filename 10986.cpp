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

// 나머지 합
int main() {
  fast;
  // arr : 누적합 계산, counter : 누적합의 나머지 갯수
  ll N, M, arr[1000001], counter[1001], answer = 0;
  memset(arr, 0, sizeof(arr));
  memset(counter, 0, sizeof(counter));
  // arr[0]은 초기값으로 먼저 계산
  cin >> N >> M >> arr[0];
  arr[0] %= M;
  counter[arr[0]] += 1;
  // 나머지 처리 하면서 누적합 계산
  for (int i = 1; i < N; i++) {
    cin >> arr[i];
    arr[i] = (arr[i] + arr[i - 1]) % M;
    counter[arr[i]] += 1;
  }
  // counter 배열을 통해 nC2 조합 계산
  for (int i = 0; i < M; i++) answer += (counter[i] * (counter[i] - 1)) / 2;
  // 마지막에 counter[0]을 더해 주는 것은 연속 부분 구간이 처음부터일 경우 추가
  cout << answer + counter[0];
}
