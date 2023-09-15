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
  int N, sum = 0;  // 숫자의 갯수, 총 합
  string strN;     // 숫자 N개
  cin >> N >> strN;
  for (int i = 0; i < N; i++) sum += strN[i] - '0';
  cout << sum;
}
