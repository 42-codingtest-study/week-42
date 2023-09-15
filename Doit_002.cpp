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

// 평균
int main() {
  fast;
  float N, score, max = 0, sum = 0;
  vector<float> NVec;
  NVec.clear();
  cin >> N;
  while (N--) {
    cin >> score;
    NVec.push_back(score);
    max = max > score ? max : score;
  }
  // 부분 합 구하기
  for (int i = 0; i < NVec.size(); i++) sum += NVec[i] / max * 100;
  cout << sum / NVec.size();
}
