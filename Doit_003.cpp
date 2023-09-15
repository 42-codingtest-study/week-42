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
  int N, M;
  ll rangeSum[100001];
  memset(rangeSum, 0, 100001);
  cin >> N >> M;
  cin >> rangeSum[0];
  // 구간 합 구하기
  for (int i = 1; i < N; i++) {
    cin >> rangeSum[i];
    rangeSum[i] += rangeSum[i - 1];
  }
  while (M--) {
    int i, j;
    cin >> i >> j;
    cout << (i != 1 ? rangeSum[j - 1] - rangeSum[i - 2] : rangeSum[j - 1])
         << "\n";
  }
}
